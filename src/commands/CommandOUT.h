#pragma once

#include "commands/Command.h"

class CommandOUT : public Command {
public:
    void apply(Processor& pro) override;
};
