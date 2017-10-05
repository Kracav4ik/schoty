#include "CommandCMP.h"
#include "Processor.h"

void CommandCMP::apply(Processor& pro) {
    int8_t a = pro.registers[aReg];
    int8_t b = pro.registers[bReg];
    if (a < b) {
        pro.registers[outReg] = -1;
    } else if (a > b) {
        pro.registers[outReg] = 1;
    } else {
        pro.registers[outReg] = 0;
    }
}
