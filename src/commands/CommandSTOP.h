#pragma once

#include "commands/Command.h"

class CommandSTOP : public Command {
public:
    void apply(Processor& pro) override;
};
