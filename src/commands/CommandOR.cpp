#include "CommandOR.h"
#include "Processor.h"

void CommandOR::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] | pro.registers[fromReg];
}
