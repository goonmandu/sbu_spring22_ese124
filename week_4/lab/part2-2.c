#include <stdio.h>

int main() {

    float user_input, temp, max, number_array[4];
    int unchanged = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter a number: ");
        scanf("%f", &user_input);
        getchar();
        number_array[i] = user_input;
    }

    if (number_array[0] > number_array[1]) {
        temp = number_array[0];
        number_array[0] = number_array[1];
        number_array[1] = temp;
    }
    if (number_array[0] > number_array[2]) {
        temp = number_array[0];
        number_array[0] = number_array[2];
        number_array[2] = temp;
    }
    if (number_array[1] > number_array[2]) {
        temp = number_array[1];
        number_array[1] = number_array[2];
        number_array[2] = temp;
    }

    max = number_array[2];
    
    printf("%f < %f < %f\n", number_array[0], number_array[1], number_array[2]);

    while (1) {
        int j;

        printf("Enter a number: ");
        scanf("%f", &number_array[3]);
        getchar();
        if (number_array[3] > max) {
            max = number_array[3];
            unchanged = 0;
        } else {
            unchanged += 1;
        }

        for (int i = 1; i < 4; i++) {  // insertion sort
            temp = number_array[i];
            j = i - 1;
            while (temp < number_array[j] && j >= 0) {
                number_array[j+1] = number_array[j];
                j -= 1;
            }
            number_array[j+1] = temp;
        }

        for (int i = 0; i < 3; i++) {
            printf("%f ", number_array[i]);
        }
        printf("\n");

        if (unchanged > 2) {
            break;
        }
    }

    return 0;
}