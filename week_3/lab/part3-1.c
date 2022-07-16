#include <stdio.h>
#include <math.h>

int main() {

    unsigned int n, p, mask;
    unsigned char user_input, operation;

    scanf("%x", &user_input);
    getchar();
    scanf("%d", &p);
    getchar();
    scanf("%d", &n);
    getchar();
    scanf("%c", &operation);
    getchar();

    mask = pow(2, n) - 1;
    mask = mask << (8 - p - n);

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
        default:
            printf("Invalid input\n");
    }

    return 0;

}