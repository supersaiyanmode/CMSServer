#ifndef STRING_DATATYPE_H
#define STRING_DATATYPE_H

#include "../BaseDataType.h"
#include <string>
#include <vector>

class String : public BaseDataType {
    std::string value;
public:
    String(const std::string&);
    std::string str();    
    operator std::string() const;
    
    
    static bool parse(const std::string&, String&,
            const std::vector<bool (*)(String)>&);
    static bool parse(const std::string&, String&, bool (*)(String)=0);
    
};

//INLINE FUNCTIONS

inline std::string String::str(){
    return value;
}

inline String::operator std::string() const{
    return value;
}

#endif