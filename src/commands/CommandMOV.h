#pragma once

#include "commands/Command.h"

class CommandMOV : public Command {
private:
    uint8_t fromReg;
    uint8_t toReg;
public:
    CommandMOV(uint8_t fromReg, uint8_t toReg) : fromReg(fromReg), toReg(toReg) {}

    void apply(Processor& pro) override;
};
