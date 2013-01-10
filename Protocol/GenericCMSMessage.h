#ifndef GENERICCMS_MESSAGE_H
#define GENERICCMS_MESSAGE_H

#include "CMSHeaderSet.h"

class GenericCMSMessage: public Serialisable{
    PredefinedCMSHeaderSet cmsHeaders;
    CMSHeaderSet customHeaders;
    std::string message;
public:
    std::string str();
};

#endif