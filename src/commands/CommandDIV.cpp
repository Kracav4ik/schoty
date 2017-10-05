#include "CommandDIV.h"
#include "Processor.h"

void CommandDIV::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] / pro.registers[fromReg];
}
