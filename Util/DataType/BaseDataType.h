#ifndef BASE_DATA_TYPE_H
#define BASE_DATA_TYPE_H

#include "../../Util/Serialisable/Serialisable.h"

class BaseDataType : Serialisable {
public:
    BaseDataType();
    virtual ~BaseDataType();
    
    virtual std::string str() =0;
};

#endif