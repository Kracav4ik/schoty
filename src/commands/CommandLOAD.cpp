#include "CommandLOAD.h"
#include "Processor.h"

void CommandLOAD::apply(Processor& pro) {
    pro.setReg(reg, pro.getMem(static_cast<uint8_t>(pro.getReg(addrR))));
}
