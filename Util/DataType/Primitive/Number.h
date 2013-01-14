#ifndef NUMBER_DATATYPE_H
#define NUMBER_DATATYPE_H

#include "../BaseDataType.h"
#include <string>
#include <vector>

class Number : public BaseDataType {
    long value;
public:
    Number(long);
    std::string str();    
    operator long() const;
    
    
    static bool parse(const std::string&, Number&,
            const std::vector<bool (*)(Number)>&);
    static bool parse(const std::string&, Number&, bool (*)(Number)=0);
    
};

//INLINE FUNCTIONS

inline Number::operator long() const{
    return value;
}

#endif