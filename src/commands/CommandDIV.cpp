#include "CommandDIV.h"
#include "Processor.h"
#include "commands/DivByZeroException.h"

void CommandDIV::apply(Processor& pro) {
    int8_t val = pro.getReg(fromReg);
    if (val == 0) {
        throw DivByZeroException();
    }
    pro.setReg(toReg, pro.getReg(toReg) / val);
}
