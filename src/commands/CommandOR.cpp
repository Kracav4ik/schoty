#include "CommandOR.h"
#include "Processor.h"

void CommandOR::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) | pro.getReg(fromReg));
}
