#include <stdio.h>
#include <string.h>
int main() {
    int main_memory [20];

    #define LOAD_WORD 0x01;
    #define STORE_WORD 0x02;
    #define ADD 0x03;
    #define SUB 0x04;
    #define HALT 0xff;

    int memory[20];
    /* organization of main memory
        0 - 13: instructions
        14-15 output
        16-17 input 1
        18-19 input 2
    */
    
    int registry[3];
    /* organization of registry
        0x00: program counter
        0x01: general purpose register
        0x02: general purpose register

    */

   void load_word(int reg, int mem_address);
   void store_word(int reg, int mem_address);
   void add_words(int reg_1, int reg_2);
   void subtract_words(int reg_1, int reg_2);
   void halt();

   /* instruction mapping
        load_word   0x01
        store_word  0x02
        add         0x03
        sub         0x04
        halt        0xff
    */
}