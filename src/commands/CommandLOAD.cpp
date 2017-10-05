#include "CommandLOAD.h"
#include "Processor.h"

void CommandLOAD::apply(Processor& pro) {
    pro.registers[reg] = pro.memory[pro.registers[addrR]];
}
