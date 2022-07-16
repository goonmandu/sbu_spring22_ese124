#include <stdio.h>

int main() {

    int num1, num2, swap;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    swap = num1;
    num1 = num2;
    num2 = swap;

    if (num1 % 2 == 0) {
        printf("First number is even\n");
    } else {
        printf("First number is odd\n");
    }

    if (num2 % 2 == 0) {
        printf("Second number is even\n");
    } else {
        printf("Second number is odd\n");
    }

    if (num1 < num2) {
        printf("%d is larger\n", num2);
    } else if (num1 > num2) {
        printf("%d is larger\n", num1);
    } else {
        printf("Two numbers are equal.\n");
    }

    return 0;
}
