#pragma once

#include "commands/Command.h"

class CommandIN : public Command {
private:
    uint8_t addr;
public:
    explicit CommandIN(uint8_t addr) : addr(addr) {}

    void apply(Processor& pro) override;
};
