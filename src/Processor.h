#pragma once

#include "commands/DecodeException.h"

#include <cstdint>

class Processor {
public:
    static const int CMD_SIZE = 2;
    static const int REG_COUNT = 16;
    static const int MEM_SIZE = 256;

private:
    int8_t registers[REG_COUNT];
    int8_t memory[MEM_SIZE];

public:
    uint8_t commandOffset;
    uint8_t nextCommandOffset;

    Processor();

    void setReg(uint8_t reg, int8_t val);
    int8_t getReg(uint8_t reg);

    void setMem(uint8_t addr, int8_t val);
    int8_t getMem(uint8_t addr);

    void reset();

    void load(const char* path);

    void step() throw(DecodeException);
};
