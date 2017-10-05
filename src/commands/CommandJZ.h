#pragma once

#include "commands/Command.h"

class CommandJZ : public Command {
public:
    void apply(Processor& pro) override;
};
