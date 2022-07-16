#include <stdio.h>

int main() {

    float user_input, prev_input;
    int pos_count = 0, neg_count = 0, zeroes = 0;
    printf("Enter a number: ");
    scanf("%f", &user_input);
    getchar();

    while (user_input != prev_input) {
        if (user_input > 0) {
            pos_count++;
        } else if (user_input < 0) {
            neg_count++;
        } else {
            zeroes++;
        }
        printf("P: %d | 0: %d | N: %d\n\n", pos_count, zeroes, neg_count);
        prev_input = user_input;
        printf("Enter a number: ");
        scanf("%f", &user_input);
        getchar();
    }

    return 0;
}