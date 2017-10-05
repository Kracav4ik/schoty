#include "CommandNOT.h"
#include "Processor.h"

void CommandNOT::apply(Processor& pro) {
    pro.registers[toReg] = ~pro.registers[toReg];
}
