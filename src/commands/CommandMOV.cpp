#include "CommandMOV.h"
#include "Processor.h"

void CommandMOV::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(fromReg));
}
