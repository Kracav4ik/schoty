#pragma once

#include "commands/Command.h"

class CommandJZ : public Command {
private:
    uint8_t checkReg;
    uint8_t addr;
public:
    CommandJZ(uint8_t checkReg, uint8_t addr) : checkReg(checkReg), addr(addr) {}

    void apply(Processor& pro) override;
};
