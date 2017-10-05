#include "CommandMUL.h"
#include "Processor.h"

void CommandMUL::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) * pro.getReg(fromReg));
}
