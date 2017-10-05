#include "CommandSTORE.h"
#include "Processor.h"

void CommandSTORE::apply(Processor& pro) {
    pro.memory[addr] = pro.registers[reg];
}
