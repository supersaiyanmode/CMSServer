#include "ManageableObjectParameter.h"

ManageableObjectParameter::ManageableObjectParameter(const std::string& name, const std::string& defaultVal,
    const std::string& description):
     parameterName(name), parameterDescription(description), defaultValue(defaultVal) {
    
}