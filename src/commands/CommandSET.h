#pragma once

#include "commands/Command.h"

class CommandSET : public Command {
public:
    void apply(Processor& pro) override;
};
