#pragma once

#include "commands/Command.h"

class CommandLOAD : public Command {
public:
    void apply(Processor& pro) override;
};
