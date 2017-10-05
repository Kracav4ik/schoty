#include "CommandSET.h"
#include "Processor.h"

void CommandSET::apply(Processor& pro) {
    pro.setReg(reg,  value);
}
