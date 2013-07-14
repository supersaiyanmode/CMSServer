#ifndef MANAGEABLE_OBJECT_PARAMETER_H
#define MANAGEABLE_OBJECT_PARAMETER_H

#include <string>

class ManageableObjectParameter {
    std::string parameterName;
    std::string parameterDescription;
    std::string defaultValue;
public:
    ManageableObjectParameter(const std::string& name, const std::string& defaultVal, const std::string& description="");
    std::string description() const; 
    std::string name() const;
};


inline std::string ManageableObjectParameter::description() const {
    return parameterDescription;
}

inline std::string ManageableObjectParameter::name() const {
    return parameterName;
}
#endif