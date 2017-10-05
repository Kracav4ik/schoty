#pragma once

#include "commands/Command.h"

class CommandSUB : public Command {
private:
    uint8_t fromReg;
    uint8_t toReg;
public:
    CommandSUB(uint8_t fromReg, uint8_t toReg) : fromReg(fromReg), toReg(toReg) {}

    void apply(Processor& pro) override;
};
