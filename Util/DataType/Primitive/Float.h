#ifndef FLOAT_DATA_TYPE_H
#define FLOAT_DATA_TYPE_H

#include "../BaseDataType.h"
#include <string>
#include <vector>

class Float : public BaseDataType {
    double value;
public:
    Float(double);
    std::string str();    
    operator double() const;
    
    
    static bool parse(const std::string&, Float&,
            const std::vector<bool (*)(Float)>&);
    static bool parse(const std::string&, Float&, bool (*)(Float)=0);
    
};


//INLINE FUNCTIONS

inline Float::operator double() const{
    return value;
}

#endif