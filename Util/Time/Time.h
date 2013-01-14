#ifndef UTIL_TIME_H
#define UTIL_TIME_H

#include <time.h>

#ifdef WIN32

#else
#include <sys/time.h>
#define PLATFORM_TIMESPAN timespec
#endif


class Time {
    unsigned long seconds_;
    unsigned long useconds_;
public:
    Time();
    ~Time();
    
    unsigned long seconds() const;
    unsigned long useconds() const;
    
    static Time now();
    static PLATFORM_TIMESPAN after(unsigned int);
};




//INLINE FUNCTIONS

inline unsigned long Time::seconds() const{
    return seconds_;
}
inline unsigned long Time::useconds() const{
    return useconds_;
}

#endif