#include <stdio.h>

int main() {

    unsigned int user_input;
    unsigned int mask = 1;
    int zeroes = 0;
    int ones = 0;

    scanf("%x", &user_input);
    getchar();

    for (int i = 0; i < 32; i++) {
        if (user_input & mask) {
            ones++;
        } else {
            zeroes++;
        }
        mask = mask << 1;
    }
    
    printf("In the number given, there are %d zeroes and %d ones.\n", zeroes, ones);

    return 0;

}
