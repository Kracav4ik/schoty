#pragma once

#include <cstdint>

class IOManager {
private:
    static IOManager* manager;

protected:
    static void set(IOManager* mgr) { manager = mgr; }

public:
    static IOManager* get() { return manager; }

    virtual void writeOutput(int8_t value) = 0;
    virtual int8_t readInput() = 0;
    virtual ~IOManager() = default;
};
