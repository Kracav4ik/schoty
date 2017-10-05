#pragma once

#include "commands/Command.h"

class CommandJMP : public Command {
public:
    void apply(Processor& pro) override;
};
