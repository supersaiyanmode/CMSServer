#ifndef TIME_SPAN_H
#define TIME_SPAN_H
#include <time.h>

#ifdef WIN32

#else
#include <sys/time.h>
#define PLATFORM_TIMESPAN timespec
#endif

class TimeSpan {
public:
    static PLATFORM_TIMESPAN getAbsoluteTimeout(unsigned int);
};

#endif