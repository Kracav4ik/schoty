#include "CommandMUL.h"
#include "Processor.h"

void CommandMUL::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] * pro.registers[fromReg];
}
