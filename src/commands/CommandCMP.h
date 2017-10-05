#pragma once

#include "commands/Command.h"

class CommandCMP : public Command {
public:
    void apply(Processor& pro) override;
};
