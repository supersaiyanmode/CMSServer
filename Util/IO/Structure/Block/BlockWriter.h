#ifndef BLOCK_WRITER_H
#define BLOCK_WRITER_H

#include <string>

#include "../../InputOutputCapable.h"

class BlockWriter {
    InputOutputCapable& device;
public:
    BlockWriter(InputOutputCapable&);
    int write(const std::string&);
    int close();
    bool writable() const;
};



//INLINE
inline bool BlockWriter::writable() const {
    return device.writable();
}
#endif