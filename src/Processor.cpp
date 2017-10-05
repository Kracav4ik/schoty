#include "Processor.h"

#include <cstring>

Processor::Processor() {
    memset(&registers, 0, sizeof(registers));
    memset(&memory, 0, sizeof(memory));
}
