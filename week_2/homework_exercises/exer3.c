#include <stdio.h>

int main() {
    
    int input, even_sum = 0, odd_sum = 0;

    while (scanf("%d", &input) == 1) {
        if (input % 2 == 0) {
            even_sum += input;
        } else {
            odd_sum += input;
        }
    }

    printf("Sum of all evens is %d\n", even_sum);
    printf("Sum of all odds is %d\n", odd_sum);

    return 0;

}