#include "CommandIN.h"
#include "Processor.h"
#include "IOManager.h"

void CommandIN::apply(Processor& pro) {
    pro.setMem(static_cast<uint8_t>(pro.getReg(addrR)), IOManager::get()->readInput());
}
