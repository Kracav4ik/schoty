#pragma once

#include "commands/Command.h"

class CommandLOAD : public Command {
private:
    uint8_t reg;
    uint8_t addrR;
public:
    CommandLOAD(uint8_t reg, uint8_t addrR) : reg(reg), addrR(addrR) {}

    void apply(Processor& pro) override;
};
