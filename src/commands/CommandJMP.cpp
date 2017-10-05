#include "CommandJMP.h"
#include "Processor.h"

void CommandJMP::apply(Processor& pro) {
    pro.nextCommandOffset = addr;
}
