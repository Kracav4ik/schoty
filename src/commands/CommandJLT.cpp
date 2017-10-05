#include "CommandJLT.h"
#include "Processor.h"

void CommandJLT::apply(Processor& pro) {
    if (pro.registers[checkReg] < 0) {
        pro.nextCommandOffset = addr;
    }
}
