#include "CommandNOT.h"
#include "Processor.h"

void CommandNOT::apply(Processor& pro) {
    pro.setReg(toReg, ~pro.getReg(toReg));
}
