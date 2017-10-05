#include "Processor.h"

#include "commands/Command.h"

Processor::Processor() {
    memset(&registers, 0, sizeof(registers));
    memset(&memory, 0, sizeof(memory));
}

void Processor::step() throw(DecodeException) {
    Command* cmd = Command::decode(0, 0);
    nextCommandOffset = static_cast<uint8_t>(commandOffset + CMD_SIZE);
    cmd->apply(*this);
    commandOffset = nextCommandOffset;
    delete cmd;
}
