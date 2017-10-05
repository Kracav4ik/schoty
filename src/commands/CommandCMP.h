#pragma once

#include "commands/Command.h"

class CommandCMP : public Command {
private:
    uint8_t outReg;
    uint8_t aReg;
    uint8_t bReg;
public:
    CommandCMP(uint8_t outReg, uint8_t aReg, uint8_t bReg) : outReg(outReg), aReg(aReg), bReg(bReg) {}

    void apply(Processor& pro) override;
};
