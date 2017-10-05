#include "CommandIN.h"
#include "Processor.h"
#include "IOManager.h"

void CommandIN::apply(Processor& pro) {
    pro.memory[pro.registers[addrR]] = IOManager::get()->readInput();
}
