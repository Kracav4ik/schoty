#pragma once

#include "commands/Command.h"

class CommandOR : public Command {
public:
    void apply(Processor& pro) override;
};
