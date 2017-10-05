#pragma once

class Processor;

class Command {
public:
    virtual void apply(Processor& pro) = 0;
    virtual ~Command() = default;
};
