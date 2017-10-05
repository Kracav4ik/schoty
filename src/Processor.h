#pragma once

#include <cinttypes>

class Processor {
public:
    static const int CMD_SIZE = 2;
    static const int REG_COUNT = 16;
    static const int MEM_SIZE = 256;

    uint8_t registers[REG_COUNT];
    uint8_t memory[MEM_SIZE];
    uint8_t commandOffset = 0;

    Processor();
};
