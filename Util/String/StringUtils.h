#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

class StringUtils {
public:
    
    static std::string ltrim(const std::string&, const std::string& = " \t\r\n");
    static std::string rtrim(const std::string&, const std::string& = " \t\r\n");
    static std::string trim(const std::string&, const std::string& = " \t\r\n");
    
    static std::vector<std::string> splitAny(const std::string&, const std::string& = " \t\n\r",
                bool = false);
    static std::vector<std::string> split(const std::string&, const std::string& = " \t\n\r",
                bool = false);
};


#endif