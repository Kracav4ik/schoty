#include "CommandXOR.h"
#include "Processor.h"

void CommandXOR::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) ^ pro.getReg(fromReg));
}
