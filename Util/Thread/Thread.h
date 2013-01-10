#ifndef THREAD_H
#define THREAD_H

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif
#include <iostream>
#include <ctime>
class ThreadBase {
public:
    static void sleep(int);    
};

template <typename T, typename P>
struct ThreadStruct {
    T* object;
    void (T::*function)(P);
    P argument;
};

template <typename T, typename P>
class Thread : public ThreadBase {
    bool cancelled;
    
    Thread(const Thread<T,P>& other): object(other.object),
            function(other.function), thread(other.thread) {
        
    }
    
    void operator=(const Thread<T,P>& rhs) {
    }
    
    Thread(T* obj, void (T::*fn)(P)):object(obj), function(fn) {
        
    }
    
public:
    
    static Thread<T,P>* createThread(T* obj, void (T::*fn)(P)) {
        return new Thread<T,P>(obj, fn);
    }
    
    void start(const P& arg){
        cancelled = false;
        ThreadStruct<T,P> ts = {object, function, arg};
        ThreadStruct<T,P>* threadStruct = new ThreadStruct<T,P>(ts);
        //std::cout<<"About to fork!\n";
    #if WIN32
        thread = CreateThread(0, 0, createThread, (void*)threadStruct, 0, 0);
    #else
        pthread_create(&thread, NULL, createThread, (void*)threadStruct);
    #endif
    }
    
    void join(){
    #if WIN32
        ::WaitForSingleObject(thread, INFINITE);
    #else
        pthread_join(thread,NULL);
    #endif
    }
    
    void kill(){
    #if WIN32
        ::TerminateThread(thread, 0);
    #else
        pthread_cancel(thread);
    #endif
        cancelled = true;
    }

    ~Thread(){
        if (!cancelled)
            kill();
    }
private:
    T* object;
    void (T::*function)(P);
    
#ifdef WIN32
    HANDLE    thread;
    static DWORD createThread(void* arg){
#else
    pthread_t thread;
    static void* createThread(void* obj){
#endif
        //std::cout<<"Forked off a new thread baby!\n";
        ThreadStruct<T,P>& data = *(ThreadStruct<T,P>*)(obj);
        P param(data.argument);
        T* object = data.object;
        void (T::*function)(P) = data.function;

        delete &data;
        (*object.*function)(param);
        return 0;
    }
};

#endif // THREAD_H
