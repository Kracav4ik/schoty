#include "CommandMOV.h"
#include "Processor.h"

void CommandMOV::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[fromReg];
}
