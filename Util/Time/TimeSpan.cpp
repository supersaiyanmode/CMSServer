#include "TimeSpan.h"

PLATFORM_TIMESPAN TimeSpan::getAbsoluteTimeout(unsigned int usec){
#ifdef WIN32

#else
    ::timeval now;
    ::timespec abstimeout;

    gettimeofday(&now, NULL);
    abstimeout.tv_sec = now.tv_sec + usec/1000000;
    abstimeout.tv_nsec = 1000L * (now.tv_usec + (usec%1000000));
    if (abstimeout.tv_nsec >= 1000000000) {
        abstimeout.tv_sec++;
        abstimeout.tv_nsec -= 1000000000;
    }
    return abstimeout;
#endif
}
