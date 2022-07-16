#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NONE 0
#define st_C 1
#define st_CY 2
#define st_CYB 3
#define st_CYBO 4
#define st_CYBOT 5
#define st_X 6
#define st_INIT NONE

int next_state_table[][6] = {
    st_C, st_X, st_X, st_X, st_X, st_X,
    st_X, st_CY, st_X, st_X, st_X, st_X,
    st_X, st_X, st_CYB, st_X, st_X, st_X,
    st_X, st_X, st_X, st_CYBO, st_X, st_X,
    st_X, st_X, st_X, st_X, st_CYBOT, st_X,
    st_CYBOT, st_CYBOT, st_CYBOT, st_CYBOT, st_CYBOT, st_CYBOT,
    st_X, st_X, st_X, st_X, st_X, st_X
};

int output_table[][6] = {
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0
};



int main() {

    char user_input[100];
    int current_state = st_INIT;
    int output;
    int saw_word = 0;

    printf("Enter a string: ");
    scanf("%s", user_input);
    getchar();

    for (int idx = 0; idx < strlen(user_input); idx++) {
        switch (tolower(user_input[idx])) {
            case 'c':
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            case 'y':
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
                break;
            case 'b':
                output = output_table[current_state][2];
                current_state = next_state_table[current_state][2];
                break;
            case 'o':
                output = output_table[current_state][3];
                current_state = next_state_table[current_state][3];
                break;
            case 't':
                output = output_table[current_state][4];
                current_state = next_state_table[current_state][4];
                break;
            default:
                output = output_table[current_state][5];
                current_state = next_state_table[current_state][5];
        }
        if (output) {
            saw_word = 1;
        }
        
        printf("%c/%d/%d\n", tolower(user_input[idx]), output, saw_word);
    }

    if (saw_word) {
        printf("String begins with CYBOTx.\n");
    } else {
        printf("String does not begin with CYBOTx.\n");
    }

    return 0;
}