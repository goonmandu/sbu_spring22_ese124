#include <stdio.h>
#include <math.h>

int main() {

    float num, result;
    char operation;


    for (int i = 0; i < 10; i++) {
        result = 0;

        // operand input
        printf("Input number: ");
        scanf("%f", &num);
        getchar();

        // operator input
        printf("Input operation: ");
        scanf("%c", &operation);
        getchar();

        // decide which operation to do based on operator input with invalid checks and prints result
        switch (operation) {
            case 'e':
                result = exp(num);
                printf("%f\n", result);
                break;
            case '/':
                if (num <= 0) {
                    printf("Invalid input.\n");
                    break;
                }
                result = log(num);
                printf("%f\n", result);
                break;
            case 'r':
                if (num < 0) {
                    printf("Invalid input.\n");
                    break;
                }
                result = sqrt(num);
                printf("%f\n", result);
                break;
            case 'm':
                result = fabs(num);
                printf("%f\n", result);
                break;
            default:
                printf("Invalid operation.\n");
        }
    }
    return 0;
}