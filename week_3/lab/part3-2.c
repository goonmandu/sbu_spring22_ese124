#include <stdio.h>
#include <math.h>

int main() {

    unsigned int user_input, n, p, mask;
    unsigned char operation;

    while (1) {
        
        printf("Enter a hexadecimal: ");
        scanf("%x", &user_input);
        getchar();
        printf("P: ");
        scanf("%d", &p);
        getchar();
        printf("N: ");
        scanf("%d", &n);
        getchar();
        printf("Operation (S, R, F, D, I, M): ");
        scanf("%c", &operation);
        getchar();

        mask = pow(2, n) - 1;
        mask = mask << (8 - p - n);

        printf("Result: ");
        switch (operation) {
            case 'S':
                user_input = user_input | mask;
                printf("%x\n", user_input);
                break;
            case 'R':
                user_input = user_input & ~mask;
                printf("%x\n", user_input);
                break;
            case 'F':
                user_input = user_input ^ mask;
                printf("%x\n", user_input);
                break;
            case 'D':
                printf("%x\n", user_input);
                break;
            case 'I':
                printf("New user input: ");
                scanf("%x\n", &user_input);
                getchar();
                break;
            case 'M':
                printf("Generated mask is %x\n", mask);
                break;
            default:
                printf("Invalid input.\n");
        }

        printf("\n");
    }

    return 0;

}