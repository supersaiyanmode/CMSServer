#ifndef INPUTOUTPUTCAPABLE_H
#define INPUTOUTPUTCAPABLE_H

#include <vector>
#include <string>

class InputOutputCapable {
public:
    virtual int write(const char*, int)=0;
    virtual int write(const std::vector<char>&)=0;
    virtual int write(const std::string&)=0;

    virtual int read(char*, int)=0;
    virtual int read(std::vector<char>&, int=8192)=0;
    virtual int read(std::string&, int=8192)=0;
    
    virtual int closeReading()=0;
    virtual int closeWriting()=0;
    
    virtual bool writable() const = 0;
    virtual bool readable() const = 0;
};

#endif
