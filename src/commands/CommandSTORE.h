#pragma once

#include "commands/Command.h"

class CommandSTORE : public Command {
private:
    uint8_t reg;
    uint8_t addrR;
public:
    CommandSTORE(uint8_t reg, uint8_t addrR) : reg(reg), addrR(addrR) {}

    void apply(Processor& pro) override;
};
