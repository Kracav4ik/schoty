#include "CommandJZ.h"
#include "Processor.h"

void CommandJZ::apply(Processor& pro) {
    if (pro.getReg(checkReg) == 0) {
        pro.nextCommandOffset = addr;
    }
}
