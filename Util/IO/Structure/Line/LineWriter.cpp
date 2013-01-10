#include "LineWriter.h"

LineWriter::LineWriter(InputOutputCapable& dv, std::string d):
        device(dv), delim(d){
    
}

int LineWriter::writeLine(const std::string& str){
    return device.write(str + delim);
}

int LineWriter::close(){
    return device.closeWriting();
}