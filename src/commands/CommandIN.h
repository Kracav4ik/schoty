#pragma once

#include "commands/Command.h"

class CommandIN : public Command {
private:
    uint8_t addrR;
public:
    explicit CommandIN(uint8_t addrR) : addrR(addrR) {}

    void apply(Processor& pro) override;
};
