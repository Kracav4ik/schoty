#include "CommandOUT.h"
#include "Processor.h"
#include "IOManager.h"

void CommandOUT::apply(Processor& pro) {
    IOManager::get()->writeOutput(pro.memory[addr]);
}
