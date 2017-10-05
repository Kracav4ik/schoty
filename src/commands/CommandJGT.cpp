#include "CommandJGT.h"
#include "Processor.h"

void CommandJGT::apply(Processor& pro) {
    if (pro.registers[checkReg] > 0) {
        pro.nextCommandOffset = addr;
    }
}
