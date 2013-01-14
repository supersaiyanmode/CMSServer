#include <sstream>

#include "Number.h"
#include "../../../Util/String/StringUtils.h"

Number::Number(long l):value(l){
    
}

std::string Number::str(){
    std::stringstream ss;
    ss<<value;
    return ss.str();
}

bool Number::parse(const std::string& str, Number& out, const std::vector<bool (*)(Number)>& conditions){
    std::stringstream ss(str);
    long l;
    ss>>l;
    if (ss.rdbuf()->in_avail() != 0){
        std::string remaining;
        std::getline(ss, remaining);
        if (StringUtils::trim(remaining).length())
            return false;
    }
    out = Number(l);
    for (std::vector<bool (*)(Number)>::const_iterator it=conditions.begin();
                        it != conditions.end(); it++){
        if (*it && !(*it)(out))
            return false;
    }
    return true;
}
bool Number::parse(const std::string& str, Number& out, bool (*condition)(Number)) {
    std::stringstream ss(str);
    long l;
    ss>>l;
    out = Number(l);
    if (condition)
        return condition(out);
    return true;
}
