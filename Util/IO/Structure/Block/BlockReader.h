#ifndef BLOCK_READER_H
#define BLOCK_READER_H

#include <string>

#include "../../InputOutputCapable.h"

class BlockReader {
    std::string backBuffer;
    InputOutputCapable& device;
public:
    BlockReader(InputOutputCapable&, const std::string& = "");
    std::string read(size_t);
    std::string getBackBuffer() const;
    int close();
    bool readable() const;
};

//INLINE FUNCTIONS
inline bool BlockReader::readable() const {
    return device.readable();
}

inline int BlockReader::close(){
    return device.closeReading();
}

inline std::string BlockReader::getBackBuffer() const{
    return backBuffer;
}

#endif