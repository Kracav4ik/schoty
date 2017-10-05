#pragma once

#include "commands/Command.h"

class CommandJGT : public Command {
private:
    uint8_t checkReg;
    uint8_t addr;
public:
    CommandJGT(uint8_t checkReg, uint8_t addr) : checkReg(checkReg), addr(addr) {}

    void apply(Processor& pro) override;
};
