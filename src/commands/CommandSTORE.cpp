#include "CommandSTORE.h"
#include "Processor.h"

void CommandSTORE::apply(Processor& pro) {
    pro.memory[pro.registers[addrR]] = pro.registers[reg];
}
