#ifdef MGMT_TEST

#include <string>

#include "ManageableObject.h"
#include "../Thread/Thread.h"
#include "../Thread/ReadWriteLock.h"

class Repeater {
    std::string name;
    Thread<Repeater,int> *thread, *serverThread;
    bool running;
    ReadWriteLock* rwLockRunning;
    ReadWriteLock* rwLockName;
    ManagementServer server;
    ManageableObject<Repeater> nameMgr;

    void run(int) {
        while (isRunning()) {
            std::cout<<"Repeater repeating: "<<getName()<<std::endl;
            ThreadBase::sleep(3000);
        }
    }
    
    void serve(int) {
        server.serve();
    }
public:
    Repeater(const std::string& n): name(n),running(true),
             server(12011), nameMgr(this, &Repeater::setName,server, "/component/repeater")  {
        thread = Thread<Repeater, int>::createThread(this, &Repeater::run);
        serverThread = Thread<Repeater, int>::createThread(this, &Repeater::serve);
        rwLockRunning = ReadWriteLock::createReadWriteLock();
        rwLockName = ReadWriteLock::createReadWriteLock();
        thread->start(0);
        serverThread->start(0);
        
        nameMgr.setParameterInfo(0, "setName", "test", "Sets the name of Repeater.");
    }
    
    bool isRunning() {
        rwLockRunning->lockRead();
        bool result = running;
        rwLockRunning->unlockRead();
        return result;
    }
    
    void setRunning(bool r) {
        rwLockRunning->lockWrite();
        running = r;
        rwLockRunning->unlockWrite();
    }
    
    std::string getName() {
        rwLockRunning->lockRead();
        std::string s = name;
        rwLockRunning->unlockRead();
        return s;
    }
    
    bool setName(const std::vector<std::string>& params, std::string& output) {
        rwLockName->lockWrite();
        name = params[0];
        rwLockName->unlockWrite();
        output = "success, set to: " + name;
        return true;
    }
};


int main() {
    Repeater r("test");
    std::string s;
    while(std::cin>>s) {
        if (s == "1")
            r.setRunning(false);
        else
            r.setName(std::vector<std::string>(1, "new"), s);
    }
    return 0;
}
#endif
