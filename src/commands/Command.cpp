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
#include "commands/CommandSTOP.h"
#include "commands/CommandSTORE.h"
#include "commands/CommandSUB.h"
#include "commands/CommandXOR.h"

Command* Command::decode(uint8_t first, uint8_t second) throw(DecodeException) {
    uint8_t op = first >> 4;
    uint8_t firstLO = first & 0xfu;
    uint8_t secondLO = second & 0xfu;
    switch (op) {
        case 1:
            // SET [R] [value]
            return new CommandSET(firstLO, static_cast<int8_t>(second));
        case 2: {
            // LOAD [R] [addrR]
            uint8_t addrR = secondLO;
            return new CommandLOAD(firstLO, addrR);
        }
        case 3: {
            // STORE [R] [addrR]
            uint8_t addrR = secondLO;
            return new CommandSTORE(firstLO, addrR);
        }
        case 4: {
            // [binop] [fromR] [toR]
            uint8_t binop = firstLO;
            uint8_t fromR = second >> 4;
            uint8_t toR = secondLO;
            switch (binop) {
                case 1:
                    // MOV [fromR] [toR]
                    return new CommandMOV(fromR, toR);
                case 2:
                    // ADD [fromR] [toR]
                    return new CommandADD(fromR, toR);
                case 3:
                    // SUB [fromR] [toR]
                    return new CommandSUB(fromR, toR);
                case 4:
                    // MUL [fromR] [toR]
                    return new CommandMUL(fromR, toR);
                case 5:
                    // DIV [fromR] [toR]
                    return new CommandDIV(fromR, toR);
                case 6:
                    // AND [fromR] [toR]
                    return new CommandAND(fromR, toR);
                case 7:
                    // OR [fromR] [toR]
                    return new CommandOR(fromR, toR);
                case 8:
                    // XOR [fromR] [toR]
                    return new CommandXOR(fromR, toR);
                case 9:
                    // NOT [unusedR] [toR]
                    return new CommandNOT(toR);
                default:
                    throw DecodeException(QString("Unknown binop %d").arg(binop));
            }
        }
        case 5: {
            // IO [IN/OUT] [addr]
            uint8_t inout = firstLO;
            uint8_t addrR = secondLO;
            switch (inout) {
                case 1:
                    // IN [addr]
                    return new CommandIN(addrR);
                case 2:
                    // OUT [addr]
                    return new CommandOUT(addrR);
                default:
                    throw DecodeException(QString("Invalid IN/OUT mode %1").arg(inout));
            }
        }
        case 6: {
            // CMP [outR] [aR] [bR]
            uint8_t aR = second >> 4;
            uint8_t bR = secondLO;
            return new CommandCMP(firstLO, aR, bR);
        }
        case 7:
            // JMP [unusedR] [addr]
            return new CommandJMP(second);
        case 8:
            // JZ [R] [addr]
            return new CommandJZ(firstLO, second);
        case 9:
            // JGT [R] [addr]
            return new CommandJGT(firstLO, second);
        case 10:
            // JLT [R] [addr]
            return new CommandJLT(firstLO, second);
        case 15:
            // STOP
            return new CommandSTOP();
        default:
            throw DecodeException(QString("Unknown opcode %1").arg(op));
    }
}
