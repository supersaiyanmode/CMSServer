#include <sstream>

#include "String.h"
#include "../../../Util/String/StringUtils.h"

String::String(const std::string& s):value(s){
    
}

bool String::parse(const std::string& str, String& out, const std::vector<bool (*)(String)>& conditions){
    out = String(str);
    for (std::vector<bool (*)(String)>::const_iterator it=conditions.begin();
                        it != conditions.end(); it++){
        if (*it && !(*it)(out))
            return false;
    }
    return true;
}
bool String::parse(const std::string& str, String& out, bool (*condition)(String)) {
    out = String(str);
    if (condition)
        return condition(out);
    return true;
}
