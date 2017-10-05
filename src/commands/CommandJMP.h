#pragma once

#include "commands/Command.h"

class CommandJMP : public Command {
private:
    uint8_t addr;
public:
    explicit CommandJMP(uint8_t addr) : addr(addr) {}

    void apply(Processor& pro) override;
};
