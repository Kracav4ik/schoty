#pragma once

#include "commands/Command.h"

class CommandNOT : public Command {
public:
    void apply(Processor& pro) override;
};
