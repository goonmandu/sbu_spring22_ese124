#include <stdio.h>
#include <math.h>

int main() {

    unsigned int user_input, p, n, mask;

    printf("Enter hexadecimal: ");
    scanf("%x", &user_input);
    printf("P: ");
    scanf("%d", &p);
    printf("N: ");
    scanf("%d", &n);

    mask = pow(2, n) - 1;
    mask = mask << (8 - p - n);

    printf("Result: %x\n", (user_input & mask) >> (8 - p - n));

    return 0;

}