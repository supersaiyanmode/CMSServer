#ifndef REQUEST_PROCESSOR_H
#define REQUEST_PROCESSOR_H

#include "../../IO/SocketIO/Connection.h"

class RequestProcessor {
protected:
    virtual void processRequest(Connection)=0;
};

#endif