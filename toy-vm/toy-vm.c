#include <stdio.h>
#include <string.h>

//instruction set
# define LOAD_WORD 0x01
# define STORE_WORD 0x02
# define ADD 0x03
# define SUB 0x04
# define HALT 0xff

//internal state
# define PROGRAM_COUNTER 0x00
# define REG_1 0x01
# define REG_2 0x02

//program
# define PROGRAM_LENGTH 14

void load_word(int reg_1, int addr ) {

}

void vm(int memory[]) {
    int registers[3];
    registers[PROGRAM_COUNTER] = 0x00;

    while(registers[PROGRAM_COUNTER] < 14) {
        int current_instruction_address = registers[PROGRAM_COUNTER];



        if (current_instruction_address == HALT) {
            break;
        }

        registers[PROGRAM_COUNTER] += 3;
    }
}

void main() {
    int program[20] = {
        LOAD_WORD, REG_1, 0x10,
        LOAD_WORD, REG_2, 0x12,
        ADD, REG_1, REG_2,
        STORE_WORD, REG_1, 0x0e,
        HALT,
        0x00,
        0x00, 0x00,
        0xa1, 0x14,
        0x0c, 0x00
    };

    vm(program);
}
