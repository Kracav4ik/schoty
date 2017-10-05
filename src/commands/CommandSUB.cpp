#include "CommandSUB.h"
#include "Processor.h"

void CommandSUB::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) - pro.getReg(fromReg));
}
