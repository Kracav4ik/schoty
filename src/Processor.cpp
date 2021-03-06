#include "Processor.h"

#include "commands/Command.h"
#include <fstream>
#include <iostream>

Processor::Processor() {
    reset();
}

void Processor::step() {
    registersRead.clear();
    registersWrite.clear();
    memoryRead.clear();
    memoryWrite.clear();
    uint8_t first = static_cast<uint8_t>(memory[commandOffset]);
    uint8_t second = static_cast<uint8_t>(memory[(commandOffset + 1) % MEM_SIZE]);
    Command* cmd = Command::decode(first, second);
    nextCommandOffset = static_cast<uint8_t>((commandOffset + CMD_SIZE) % MEM_SIZE);
    cmd->apply(*this);
    commandOffset = nextCommandOffset;
    delete cmd;
}

void Processor::load(const char* path) {
    reset();
    std::ifstream in(path);
    int addr = 0;
    while (in && addr < MEM_SIZE) {
        std::string s;
        in >> s;
        try {
            memory[addr] = static_cast<int8_t>(std::stoi(s, nullptr, 16));
            ++addr;
        } catch (const std::invalid_argument& unused) {}
    }
}

void Processor::reset() {
    memset(&registers, 0, sizeof(registers));
    memset(&memory, 0, sizeof(memory));
    commandOffset = 0;
    nextCommandOffset = 0;
}

int8_t Processor::getReg(uint8_t reg) {
    registersRead.append(reg);
    return registers[reg];
}

void Processor::setReg(uint8_t reg, int8_t val) {
    registersWrite.append(reg);
    registers[reg] = val;
}

int8_t Processor::getMem(uint8_t addr) {
    memoryRead.append(addr);
    return memory[addr];
}

void Processor::setMem(uint8_t addr, int8_t val) {
    memoryWrite.append(addr);
    memory[addr] = val;
}
