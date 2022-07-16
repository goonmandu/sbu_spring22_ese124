#include <stdio.h>

int main() {

    unsigned int num1;
    unsigned char mask = 0b1111;
    scanf("%x", &num1);

    printf("%x\n", num1 | mask);
    return 0;
    
}
