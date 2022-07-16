#include <stdio.h>

int main() {

    unsigned char num1 = 0x12;
    unsigned char num2 = 0xda;
    unsigned char num3 = 0x3b;
    unsigned char num4 = 0xbe;
    unsigned int user_input;

    scanf("%x", &user_input);

    printf("x: %x, d: %d, c: %c\n", num1, num1, num1);
    printf("x: %x, d: %d, c: %c\n", num2, num2, num2);
    printf("x: %x, d: %d, c: %c\n", num3, num3, num3);
    printf("x: %x, d: %d, c: %c\n", num4, num4, num4);
    
    // It is different because:
    // %x encodes the value in hexadecimal,
    // %d encodes the value in decimal, and
    // %c encodes the value as the corresponding ASCII character.

    printf("%x\n", num1 & num2);
    printf("%x\n", num1 | num2);
    printf("%x\n", num1 ^ num2);
    printf("%x\n", num3 & num4);
    printf("%x\n", num3 | num4);
    printf("%x\n", num3 ^ num4);

    return 0;

}