
#include "stdio.h"

int main() {
    int n = 10;
    int total = 0;
    
    for (int i = 0; i <= n; i++)
        total += i;
    
    printf("Total is: %d\n", total);
}