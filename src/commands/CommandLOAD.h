#pragma once

#include "commands/Command.h"

class CommandLOAD : public Command {
private:
    uint8_t reg;
    uint8_t addr;
public:
    CommandLOAD(uint8_t reg, uint8_t addr) : reg(reg), addr(addr) {}

    void apply(Processor& pro) override;
};
