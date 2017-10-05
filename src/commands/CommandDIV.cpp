#include "CommandDIV.h"
#include "Processor.h"

void CommandDIV::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) / pro.getReg(fromReg));
}
