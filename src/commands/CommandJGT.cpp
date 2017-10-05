#include "CommandJGT.h"
#include "Processor.h"

void CommandJGT::apply(Processor& pro) {
    if (pro.getReg(checkReg) > 0) {
        pro.nextCommandOffset = addr;
    }
}
