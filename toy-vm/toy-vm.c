#include <stdio.h>
#include <string.h>
int main() {
    int main_memory [20];

    #define LOAD_WORD 0x01;
    #define STORE_WORD 0x02;
    #define ADD 0x03;
    #define SUB 0x04;
    #define HALT 0xff;

    

    /* organization of main memory
        0 - 13: instructions
        14-15 output
        16-17 input 1
        18-19 input 2
    */

   /* instruction mapping
        load_word   0x01
        store_word  0x02
        add         0x03
        sub         0x04
        halt        0xff
    */
}