#include "CommandCMP.h"
#include "Processor.h"

void CommandCMP::apply(Processor& pro) {
    int8_t a = pro.getReg(aReg);
    int8_t b = pro.getReg(bReg);
    if (a < b) {
        pro.setReg(outReg, -1);
    } else if (a > b) {
        pro.setReg(outReg, 1);
    } else {
        pro.setReg(outReg, 0);
    }
}
