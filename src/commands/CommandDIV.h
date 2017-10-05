#pragma once

#include "commands/Command.h"

class CommandDIV : public Command {
public:
    void apply(Processor& pro) override;
};
