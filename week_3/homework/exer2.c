#include <stdio.h>

int main() {
    
    unsigned int user_input;
    unsigned int mask = 0x80000000;
    int leading_zeroes = 0;
    
    scanf("%x", &user_input);
    getchar();

    while (!(mask & user_input) && leading_zeroes < sizeof(user_input) * 8) {
        leading_zeroes++;
        mask = mask >> 1;
    }

    printf("In the number given, there are %d leading zeroes.\n", leading_zeroes);

    return 0;
}
