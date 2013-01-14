#include <sstream>

#include "Float.h"
#include "../../../Util/String/StringUtils.h"

Float::Float(double l):value(l){
    
}

std::string Float::str(){
    std::stringstream ss;
    ss<<value;
    return ss.str();
}

bool Float::parse(const std::string& str, Float& out, const std::vector<bool (*)(Float)>& conditions){
    std::stringstream ss(str);
    double l;
    ss>>l;
    if (ss.rdbuf()->in_avail() != 0){
        std::string remaining;
        std::getline(ss, remaining);
        if (StringUtils::trim(remaining).length())
            return false;
    }
    out = Float(l);
    for (std::vector<bool (*)(Float)>::const_iterator it=conditions.begin();
                        it != conditions.end(); it++){
        if (*it && !(*it)(out))
            return false;
    }
    return true;
}
bool Float::parse(const std::string& str, Float& out, bool (*condition)(Float)) {
    std::stringstream ss(str);
    double l;
    ss>>l;
    out = Float(l);
    if (condition)
        return condition(out);
    return true;
}
