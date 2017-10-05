#include "CommandSET.h"
#include "Processor.h"

void CommandSET::apply(Processor& pro) {
    pro.registers[reg] = value;
}
