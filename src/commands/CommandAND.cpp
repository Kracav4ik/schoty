#include "CommandAND.h"
#include "Processor.h"

void CommandAND::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) & pro.getReg(fromReg));
}
