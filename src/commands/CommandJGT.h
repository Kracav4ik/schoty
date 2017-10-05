#pragma once

#include "commands/Command.h"

class CommandJGT : public Command {
public:
    void apply(Processor& pro) override;
};
