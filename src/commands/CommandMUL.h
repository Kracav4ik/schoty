#pragma once

#include "commands/Command.h"

class CommandMUL : public Command {
public:
    void apply(Processor& pro) override;
};
