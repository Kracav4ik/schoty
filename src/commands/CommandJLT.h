#pragma once

#include "commands/Command.h"

class CommandJLT : public Command {
public:
    void apply(Processor& pro) override;
};
