#pragma once

#include "commands/Command.h"

class CommandJLT : public Command {
private:
    uint8_t checkReg;
    uint8_t addr;
public:
    CommandJLT(uint8_t checkReg, uint8_t addr) : checkReg(checkReg), addr(addr) {}

    void apply(Processor& pro) override;
};
