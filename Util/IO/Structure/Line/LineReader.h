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
    std::string getBackBuffer() const;
    bool readable() const;
    bool writable() const;
};


//INLINE FUNCTIONS

inline bool LineReader::readable() const {
    return device.readable();
}

inline int LineReader::close(){
    return device.closeReading();
}

inline std::string LineReader::getBackBuffer() const{
    return backBuffer;
}
#endif