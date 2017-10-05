#pragma once

#include "commands/Command.h"

class CommandAND : public Command {
public:
    void apply(Processor& pro) override;
};
