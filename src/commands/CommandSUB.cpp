#include "CommandSUB.h"
#include "Processor.h"

void CommandSUB::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] - pro.registers[fromReg];
}
