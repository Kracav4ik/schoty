#include "CommandJLT.h"
#include "Processor.h"

void CommandJLT::apply(Processor& pro) {
    if (pro.getReg(checkReg) < 0) {
        pro.nextCommandOffset = addr;
    }
}
