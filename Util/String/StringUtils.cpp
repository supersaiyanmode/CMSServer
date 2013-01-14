#include "StringUtils.h"

std::string StringUtils::ltrim(const std::string& s, const std::string& trimChars){
    std::string ret(s);
    size_t pos = ret.find_first_not_of(trimChars);
    if (pos != std::string::npos)
        ret.substr(pos).swap(ret);
    return ret;
}

std::string StringUtils::rtrim(const std::string& s, const std::string& trimChars){
    std::string ret(s);
    size_t pos = ret.find_last_not_of(trimChars);
    if (pos != std::string::npos)
        ret.substr(0, pos+1).swap(ret);
    return ret;
}

std::string StringUtils::trim(const std::string& s, const std::string& trimChars){
    return ltrim(rtrim(s,trimChars), trimChars);
}