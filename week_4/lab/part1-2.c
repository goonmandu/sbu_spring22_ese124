#include <stdio.h>
#include <math.h>

int main() {

    int user_input, sum = 0, coefficient = 0;
    printf("Enter a number: ");
    scanf("%d", &user_input);
    getchar();

    for (int i = 0; i < user_input; i++) {
        for (int j = 0; j < i+1; j++) {
            int result = 1;
            for (int exponent = j; exponent > 0; exponent--) {
                result *= 10;
            }
            coefficient += result;
        }
        sum += 9 * coefficient;
        coefficient = 0;
    }

    printf("Result: %d\n", sum);
    return 0;
}