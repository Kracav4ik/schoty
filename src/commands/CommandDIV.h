#pragma once

#include "commands/Command.h"

class CommandDIV : public Command {
private:
    uint8_t fromReg;
    uint8_t toReg;
public:
    CommandDIV(uint8_t fromReg, uint8_t toReg) : fromReg(fromReg), toReg(toReg) {}

    void apply(Processor& pro) override;
};
