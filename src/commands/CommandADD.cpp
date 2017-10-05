#include "CommandADD.h"
#include "Processor.h"

void CommandADD::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] + pro.registers[fromReg];
}
