#ifndef LINE_READER_H
#define LINE_READER_H

#include <string>

#include "../../InputOutputCapable.h"

class LineReader {
    std::string backBuffer;
    InputOutputCapable& device;
    std::string delim;
public:
    LineReader(InputOutputCapable&, std::string="\n");
    std::string readLine();
    int close();
};

#endif