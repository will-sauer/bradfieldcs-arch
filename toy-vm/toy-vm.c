#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
# define REGISTER_LENGTH 5

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
    int sum = memory[mem_addr] + (memory[mem_addr + 1] * 256);
    registers[reg_addr] = sum;    
}

void add(int reg_addr_1, int reg_addr_2, int registers[] ) {
    int sum = registers[reg_addr_1] + registers[reg_addr_2];
    registers[reg_addr_1] = sum;
}

void store_word(int reg_addr, int mem_addr, int memory[], int registers[] ) {
    memory[mem_addr] = registers[reg_addr] % 256;
    memory[mem_addr + 1] = registers[reg_addr] / 256;
}

void vm(int memory[]) {
    int registers[3];

    registers[PROGRAM_COUNTER] = 0x00;

    printf("Registers before:\n");
    print_registers(registers);

    while(registers[PROGRAM_COUNTER] < 14) {
        int current_instruction_address = registers[PROGRAM_COUNTER];
        int current_instruction = memory[current_instruction_address];

        printf("Instruction address %02x  ", registers[PROGRAM_COUNTER]);
        printf("Instruction code %02x", current_instruction);
        printf("\n");        

        if (current_instruction == HALT) {
            break;
        }
        else if (current_instruction == LOAD_WORD) {
            load_word(memory[current_instruction_address + 1], memory[current_instruction_address + 2], memory, registers);
        }
        else if (current_instruction == ADD) {
            add(memory[current_instruction_address + 1], memory[current_instruction_address + 2], registers);
        }
        else if (current_instruction == STORE_WORD) {
            store_word(memory[current_instruction_address + 1], memory[current_instruction_address + 2], memory, registers);
        }

        registers[PROGRAM_COUNTER] += 3;
    }

    printf("Registers after:\n");
    print_registers(registers);
}

bool arrays_match(int arr_1[], int arr_2[]) {
    int current_position = 0;
    while(current_position < PROGRAM_LENGTH) {
        if(arr_1[current_position] != arr_2[current_position])
            return false;
        
        current_position++;
    }
    return true;
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

    int expected_memory[MEMORY_LENGTH] = {
        LOAD_WORD, REG_1, 0x10,
        LOAD_WORD, REG_2, 0x12,
        ADD, REG_1, REG_2,
        STORE_WORD, REG_1, 0x0e,
        HALT,
        0x00,
        0xad, 0x14,
        0xa1, 0x14,
        0x0c, 0x00
    };

    printf("Memory before:\n");
    print_memory(program);
    vm(program);
    printf("Memory after:\n");
    print_memory(program);
    printf("Memory expected:\n");
    print_memory(expected_memory);

    printf("Matches expected result? -- ");
    printf("%s", arrays_match(expected_memory, program) ? "true \n" : "false \n");
}
