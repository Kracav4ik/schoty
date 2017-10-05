#pragma once

#include "commands/Command.h"

class CommandNOT : public Command {
private:
    uint8_t toReg;
public:
    explicit CommandNOT(uint8_t toReg) : toReg(toReg) {}

    void apply(Processor& pro) override;
};
