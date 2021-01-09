#include <stdio.h>
#include <string.h>

int main() {
    int program[20] = {
        0x01, 0x02, 0x12,
        0x03, 0x01, 0x02,
        0x01, 0x01, 0x10,
        0x02, 0x01, 0x0e,
        0xff,
        0x00,
        0x00, 0x00,
        0xa1, 0x14,
        0x0c, 0x00
    };
   

   void load_word(int reg, int mem_address);
   void store_word(int reg, int mem_address);
   void add_words(int reg_1, int reg_2);
   void subtract_words(int reg_1, int reg_2);
   void halt();
   void virtual_computer(int program[]);

   void virtual_computer(program) {
        int registry[3] = {0x00, 0x00, 0x00};
        
        int current_instruction = program[registry[0x00]];
        while(current_instruction != HALT && registry[0x00] < 20) {
        

            case(current_instruction) {
                case 0x01:
                    register_number = program[current_instruction + 0x01];
                    input_value = program[current_instruction + 0x02];
                    load_word(register_number, input_value);
                    break;
                case 0x02: 
                    register_number = program[current_instruction + 0x01];
                    input_value = program[current_instruction + 0x02];
                    store_word(register_number, input_value);
                    break;
                case 0x03:
                    int addend_1_location = program[current_instruction + 0x01];
                    int addend_2_location = program[current_instruction + 0x02];
                    add(addend_1_location, addend_2_location);
                    break;
                case 0x04: 
                    int minuend = program[current_instruction + 0x01];
                    int subtrahend = program[current_instruction + 0x02];
                    subtract(minuend, subtrahend);
                    break;
                case 0xff: 
                    halt();
                    break;
            };

            registry[0x00]++;
            current_instruction = program[registry[0x00]];
        };

        return void;
   };
};
