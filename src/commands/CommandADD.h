#pragma once

#include "commands/Command.h"

class CommandADD : public Command {
public:
    void apply(Processor& pro) override;
};
