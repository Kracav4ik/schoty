#include "CommandSTOP.h"
#include "commands/StopException.h"

void CommandSTOP::apply(Processor& pro) {
    throw StopException();
}
