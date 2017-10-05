#pragma once

#include "commands/Command.h"

class CommandOUT : public Command {
private:
    uint8_t addr;
public:
    explicit CommandOUT(uint8_t addr) : addr(addr) {}

    void apply(Processor& pro) override;
};
