#include <iostream>
#include <cstdlib>

#include "ThreadLogger.h"
#include "Mutex.h"

Mutex* displayMutex;

void deleteDisplayMutex(){
    if (displayMutex)
        delete displayMutex;
}


void threadDisplay(const std::string& line){
    if (!displayMutex){
         displayMutex = Mutex::createMutex();
         std::atexit(deleteDisplayMutex);
    }
    
    displayMutex->acquire();
    std::cout<<line<<std::endl;
    displayMutex->release();
}