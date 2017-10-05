#include "CommandSTORE.h"
#include "Processor.h"

void CommandSTORE::apply(Processor& pro) {
    pro.setMem(static_cast<uint8_t>(pro.getReg(addrR)), pro.getReg(reg));
}
