#pragma once

#include "commands/Command.h"

class CommandMOV : public Command {
public:
    void apply(Processor& pro) override;
};
