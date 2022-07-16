#include <stdio.h>
#include <math.h>

int main() {

    unsigned int user_input_1, user_input_2, p, n, mask_1, mask_2;

    printf("First hexadecimal: ");
    scanf("%x", &user_input_1);
    printf("Second hexadecimal: ");
    scanf("%x", &user_input_2);
    printf("P: ");
    scanf("%d", &p);
    printf("N: ");
    scanf("%d", &n);

    mask_2 = pow(2, n) - 1;
    mask_1 = mask_2 << (8 - p - n);

    printf("Result: %x\n", (user_input_1 & ~mask_1) | ((user_input_2 & mask_2) << (8 - p - n)));

    return 0;
}