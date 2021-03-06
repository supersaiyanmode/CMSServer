#include "CMSDestination.h"
#include "../../Util/String/StringUtils.h"
#include "../Exception/ProtocolException.h"

CMSDestination::CMSDestination() {
    CMSDestGroup::type = NONE;
}

CMSDestination::CMSDestination(const std::string& s): CMSDestGroup(s) {
    //Guaranteed to be atleast X.Y
    if (CMSDestGroup::parts.back() == ">")
        throw ProtocolException("CMSDestination contains a trailing '>': " + s);
}

CMSDestination::~CMSDestination(){
    
}