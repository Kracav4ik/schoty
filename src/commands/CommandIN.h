#pragma once

#include "commands/Command.h"

class CommandIN : public Command {
public:
    void apply(Processor& pro) override;
};
