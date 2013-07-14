#ifndef MANAGEABLE_H
#define MANAGEABLE_H

#include <vector>
#include <string>

#include "ManageableObjectParameter.h"

class Manageable {
public:
    virtual bool invoke(const std::vector<std::string>& input, std::string& output) = 0;
    virtual const std::vector<ManageableObjectParameter>& parametersInfo() const = 0;
};

#endif