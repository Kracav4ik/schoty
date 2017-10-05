#include "Command.h"

#include "commands/CommandADD.h"
#include "commands/CommandAND.h"
#include "commands/CommandCMP.h"
#include "commands/CommandDIV.h"
#include "commands/CommandIN.h"
#include "commands/CommandJGT.h"
#include "commands/CommandJLT.h"
#include "commands/CommandJMP.h"
#include "commands/CommandJZ.h"
#include "commands/CommandLOAD.h"
#include "commands/CommandMOV.h"
#include "commands/CommandMUL.h"
#include "commands/CommandNOT.h"
#include "commands/CommandOR.h"
#include "commands/CommandOUT.h"
#include "commands/CommandSET.h"
#include "commands/CommandSTORE.h"
#include "commands/CommandSUB.h"
#include "commands/CommandXOR.h"

Command* Command::decode(uint8_t first, uint8_t second) throw(DecodeException) {
    uint8_t op = first >> 4;
    uint8_t firstLO = first & 0xfu;
    switch (op) {
        case 1:
            // SET [R] [value]
            return new CommandSET();
        case 2:
            // LOAD [R] [addr]
            return new CommandLOAD();
        case 3:
            // STORE [R] [addr]
            return new CommandSTORE();
        case 4: {
            // [binop] [fromR] [toR]
            uint8_t binop = firstLO;
            uint8_t fromR = second >> 4;
            uint8_t toR = second & 0xfu;
            switch (binop) {
                case 1:
                    // MOV [fromR] [toR]
                    return new CommandMOV();
                case 2:
                    // ADD [fromR] [toR]
                    return new CommandADD();
                case 3:
                    // SUB [fromR] [toR]
                    return new CommandSUB();
                case 4:
                    // MUL [fromR] [toR]
                    return new CommandMUL();
                case 5:
                    // DIV [fromR] [toR]
                    return new CommandDIV();
                case 6:
                    // AND [fromR] [toR]
                    return new CommandAND();
                case 7:
                    // OR [fromR] [toR]
                    return new CommandOR();
                case 8:
                    // XOR [fromR] [toR]
                    return new CommandXOR();
                case 9:
                    // NOT [unusedR] [toR]
                    return new CommandNOT();
                default:
                    throw DecodeException(QString("Unknown binop %d").arg(binop));
            }
        }
        case 5: {
            // IO [IN/OUT] [addr]
            uint8_t inout = firstLO;
            switch (inout) {
                case 1:
                    // IN [addr]
                    return new CommandIN();
                case 2:
                    // OUT [addr]
                    return new CommandOUT();
                default:
                    throw DecodeException(QString("Invalid IN/OUT mode %1").arg(inout));
            }
        }
        case 6:
            // CMP [outR] [aR] [bR]
            return new CommandCMP();
        case 7:
            // JMP [unusedR] [addr]
            return new CommandJMP();
        case 8:
            // JZ [R] [addr]
            return new CommandJZ();
        case 9:
            // JGT [R] [addr]
            return new CommandJGT();
        case 10:
            // JLT [R] [addr]
            return new CommandJLT();
        default:
            throw DecodeException(QString("Unknown opcode %1").arg(op));
    }
}
