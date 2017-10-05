#pragma once

#include "commands/Command.h"

class CommandSTORE : public Command {
public:
    void apply(Processor& pro) override;
};
