#include "LineWriter.h"

LineWriter::LineWriter(InputOutputCapable& dv, std::string d):
        device(dv), delim(d) {
    
}

int LineWriter::writeLine(const std::string& str){
    if (!writable())
        return -1;
    return device.write(str + delim);
}
