#pragma once

#include "commands/Command.h"

class CommandAND : public Command {
private:
    uint8_t fromReg;
    uint8_t toReg;
public:
    CommandAND(uint8_t fromReg, uint8_t toReg) : fromReg(fromReg), toReg(toReg) {}

    void apply(Processor& pro) override;
};
