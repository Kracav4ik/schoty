#pragma once

#include "commands/Command.h"

class CommandSUB : public Command {
public:
    void apply(Processor& pro) override;
};
