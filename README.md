# Schoty
**Schoty** is a simulation of a primitive processor with 2-byte instructions. It is also a [Russian flavor of abacus](https://en.wikipedia.org/wiki/Abacus#Russian) commonly known as [Счёты](https://ru.wikipedia.org/wiki/Счёты).

## Specifications
**Schoty** has 16 1-byte registers. It is also able to address 256 1-byte cells of memory. Depending on usage context, register and memory contents are interpreted either as unsigned or as signed 8-bit integers.

## Commands
All commands are 2-byte words. Each byte consists of two nibbles. The first nibble of the first byte is the command opcode.
```
+-----------------+-----------------+
|   first byte    |   second byte   |
+--------+--------+--------+--------+
| opcode |        |        |        |
+--------+--------+--------+--------+
```
### `opcode` **COMMAND NAME** &mdash; description
### `1` **SET** &mdash; set constant to register
### `2` **LOAD** &mdash; load value from memory
### `3` **STORE** &mdash; save value to memory
### `4` Inplace operations X op= Y
#### `41` **MOV** &mdash; assignment: X = Y
#### `42` **ADD** &mdash; addition: X = X + Y
#### `43` **SUB** &mdash; subtraction: X = X - Y
#### `44` **MUL** &mdash; multiplication: X = X * Y
#### `45` **DIV** &mdash; division: X = X / Y
#### `46` **AND** &mdash; bitwise *and*: X = X & Y
#### `47` **OR** &mdash; bitwise *or*: X = X | Y
#### `48` **XOR** &mdash; bitwise *xor*: X = X ^ Y
#### `49` **NOT** &mdash; inversion: X = ~X
### `5` IO operations
#### `51` **IN** &mdash; input character from console
#### `52` **OUT** &mdash; output character to console
### `6` **CMP** &mdash; compare register values
### `7` **JMP** &mdash; unconditional jump
### `8` **JZ** &mdash; jump if zero
### `9` **JGT** &mdash; jump if greater-than zero
### `a` **JLT** &mdash; jump if less-then zero
### `f` **STOP** &mdash; stop execution
