#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NONE 0
#define st_F 1
#define st_FR 2
#define st_FRO 3
#define st_FROG 4
#define st_INIT NONE

int next_state_table[][5] = {
    st_F, NONE, NONE, NONE, NONE,
    st_F, st_FR, NONE, NONE, NONE,
    st_F, NONE, st_FRO, NONE, NONE,
    st_F, NONE, NONE, st_FROG, NONE,
    st_F, NONE, NONE, NONE, NONE
};

int output_table[][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 0,
    0, 0, 0, 0, 0
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
            case 'f':
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            case 'r':
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
                break;
            case 'o':
                output = output_table[current_state][2];
                current_state = next_state_table[current_state][2];
                break;
            case 'g':
                output = output_table[current_state][3];
                current_state = next_state_table[current_state][3];
                break;
            default:
                output = output_table[current_state][4];
                current_state = next_state_table[current_state][4];
        }

        if (output) {
            saw_word = 1;
        }

        printf("%c/%d/%d\n", tolower(user_input[idx]), output, saw_word);
    }

    if (saw_word) {
        printf("FROG detected\n");
    } else {
        printf("FROG not detected\n");
    }

    return 0;
}