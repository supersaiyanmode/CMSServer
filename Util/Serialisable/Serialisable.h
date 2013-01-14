#ifndef SERIALISABLE_H
#define SERIALISABLE_H
#include <string>

class Serialisable {
public:
    virtual std::string str() =0; //Wont be const, For eg, headers like Content-Length are modified.
};

#endif