#pragma once

#include "commands/Command.h"

class CommandOUT : public Command {
private:
    uint8_t addrR;
public:
    explicit CommandOUT(uint8_t addrR) : addrR(addrR) {}

    void apply(Processor& pro) override;
};
