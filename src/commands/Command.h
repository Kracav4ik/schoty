#pragma once

#include "commands/DecodeException.h"

#include <cstdint>

class Processor;

class Command {
public:
    static Command* decode(uint8_t first, uint8_t second) throw(DecodeException);

    virtual void apply(Processor& pro) = 0;
    virtual ~Command() = default;
};
