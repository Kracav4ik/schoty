#pragma once

#include "commands/Command.h"

class CommandXOR : public Command {
public:
    void apply(Processor& pro) override;
};
