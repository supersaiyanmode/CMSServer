#ifndef MANAGEMENT_CORE_H
#define MANAGEMENT_CORE_H

#include <string>
#include <vector>

#include "Manageable.h"
#include "ManagementServer.h"
#include "ManageableObjectParameter.h"
#include "../String/StringUtils.h"

template<typename T>
class ManageableObject : public Manageable {
    T* object;
    bool (T::*function)(const std::vector<std::string>&, std::string&);
    std::vector<ManageableObjectParameter> parameters;
    ManagementServer& instance;
public:
    ManageableObject(
            T* obj,
            bool (T::*func)(const std::vector<std::string>& paramArr, std::string&),
            ManagementServer& inst, std::string path) : 
                object(obj), function(func), instance(inst){
        //register path
        instance.registerObject(path, this);
    }
    
    virtual ~ManageableObject() {}
    
    bool invoke(const std::vector<std::string>& input, std::string& output) {
        try {
            return (object->*function)(input, output);
        } catch ( ... ) {
            output = "";
            return false;
        }
    }
    
    const std::vector<ManageableObjectParameter>& parametersInfo() const {
        return parameters;
    }
    
    bool setParameterInfo(size_t index, const std::string& name, const std::string& defaultVal, const std::string& description="") {
        if (index > parameters.size())
            return false;
        if (index == parameters.size()) {
            parameters.push_back(ManageableObjectParameter(name, defaultVal, description));
        } else {
            parameters[index] = ManageableObjectParameter(name, defaultVal, description);
        }
        return true;
            
    }
};

#endif