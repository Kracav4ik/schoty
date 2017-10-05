#include "CommandADD.h"
#include "Processor.h"

void CommandADD::apply(Processor& pro) {
    pro.setReg(toReg, pro.getReg(toReg) + pro.getReg(fromReg));
}
