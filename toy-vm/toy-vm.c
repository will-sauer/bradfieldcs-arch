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
# define REGISTER_LENGTH 3

//program
# define PROGRAM_LENGTH 14
# define MEMORY_LENGTH 20

void print_memory(int memory[]) {
    for(int position = 0; position < MEMORY_LENGTH; position++)
      printf("%02x ", position);
    printf("\n");
    for(int position = 0; position < MEMORY_LENGTH; position++)
      printf("%02x ", memory[position]);
    printf("\n");
}

void print_registers(int registers[]) {
    for(int position = 0; position < REGISTER_LENGTH; position++)
      printf("%02x ", position);
    printf("\n");
    for(int position = 0; position < REGISTER_LENGTH; position++)
      printf("%02x ", registers[position]);
    printf("\n");
}

void load_word(int reg_addr, int mem_addr, int memory[], int registers[] ) {
    registers[reg_addr] = memory[mem_addr];
}

void vm(int memory[]) {
    int registers[3];

    registers[PROGRAM_COUNTER] = 0x00;

    printf("Registers before:\n");
    print_registers(registers);

    while(registers[PROGRAM_COUNTER] < 14) {
        int current_instruction_address = registers[PROGRAM_COUNTER];

        if (current_instruction_address == HALT) {
            break;
        }
        else if (current_instruction_address == LOAD_WORD) {
            load_word(current_instruction_address + 1, current_instruction_address + 2, memory, registers);
        }

        registers[PROGRAM_COUNTER] += 3;
    }

    printf("Registers after:\n");
    print_registers(registers);

}


void main() {
    int program[MEMORY_LENGTH] = {
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

    printf("Memory before:\n");
    print_memory(program);
    vm(program);
    printf("Memory after:\n");
    print_memory(program);
}
