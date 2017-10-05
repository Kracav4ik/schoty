#include "CommandAND.h"
#include "Processor.h"

void CommandAND::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] & pro.registers[fromReg];
}
