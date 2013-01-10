#ifndef CMS_HEADER_SET
#define CMS_HEADER_SET

#include <map>

#include "../Util/Serialisable.h"
#include "CMSHeaderDefinition.h"
class CMSHeaderSet: public Serialisable {
    std::map<std::string, CMSHeaderDefinition> headers;
public:
    std::string str();
};

#endif