#ifndef LINE_WRITER_H
#define LINE_WRITER_H

#include <string>

#include "../../InputOutputCapable.h"

class LineWriter {
    std::string backBuffer;
    InputOutputCapable& device;
    std::string delim;
public:
    LineWriter(InputOutputCapable&, std::string="\n");
    int writeLine(const std::string&);
    int close();
};

#endif