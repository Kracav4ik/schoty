#pragma once

#include "commands/Command.h"

class CommandSET : public Command {
private:
    uint8_t reg;
    int8_t value;
public:
    CommandSET(uint8_t reg, int8_t value) : reg(reg), value(value) {}

    void apply(Processor& pro) override;
};
