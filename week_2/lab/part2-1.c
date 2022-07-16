#include <stdio.h>

int main() {

    float sum = 0;
    float user_input;

    // infinite loop
    while (1) {
        
        // get user input and remove tailing newline
        scanf("%f", &user_input);
        getchar();

        // add user input to previous sum and print sum
        sum += user_input;
        printf("%f\n", sum);
    }

    return 0;
    
}