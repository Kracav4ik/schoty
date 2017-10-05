#include "CommandXOR.h"
#include "Processor.h"

void CommandXOR::apply(Processor& pro) {
    pro.registers[toReg] = pro.registers[toReg] ^ pro.registers[fromReg];
}
