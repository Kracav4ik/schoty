#include "CommandOUT.h"
#include "Processor.h"
#include "IOManager.h"

void CommandOUT::apply(Processor& pro) {
    IOManager::get()->writeOutput(pro.getMem(static_cast<uint8_t>(pro.getReg(addrR))));
}
