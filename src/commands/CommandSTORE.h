#pragma once

#include "commands/Command.h"

class CommandSTORE : public Command {
private:
    uint8_t reg;
    uint8_t addr;
public:
    CommandSTORE(uint8_t reg, uint8_t addr) : reg(reg), addr(addr) {}

    void apply(Processor& pro) override;
};
