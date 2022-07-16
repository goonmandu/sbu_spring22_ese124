#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define NONE 0
#define st_E 1
#define st_O 2
#define st_EO 3
#define st_EE 4
#define st_OO 5
#define st_OE 6
#define st_INIT NONE

int next_state_table[][2] = {
    st_O, st_E,
    st_EO, st_EE,
    st_OO, st_OE,
    st_OO, st_OE,
    st_EO, st_EE,
    st_OO, st_OE,
    st_EO, st_EE
};

int output_table[][2] = {
    0, 0,
    0, 0,
    0, 0,
    1, 0,
    0, 0,
    0, 1,
    1, 0
};

int main() {

    int input;
    int is_odd;
    int current_state = st_INIT;
    int output;
    int saw_word = 0;

    while (1) {
        printf("Enter an integer: ");
        scanf("%d", &input);
        getchar();
        is_odd = input % 2;
        switch (abs(is_odd)) {
            case 1:
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            default:
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
        }
        if (output) {
            printf("There are 2 odd numbers in the last 3.\n");
        } else {
            printf("There are NOT 2 odd numbers in the last 3.\n");
        }
    }

    return 0;
}