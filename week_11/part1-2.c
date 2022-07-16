#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NONE 0
#define st_M 1
#define st_MU 2
#define st_MUR 3
#define st_MURM 4
#define st_MURMU 5
#define st_MURMUR 6
#define st_MURMURS 7
#define st_INIT NONE

int next_state_table[][5] = {
    st_M, NONE, NONE, NONE, NONE,
    st_M, st_MU, NONE, NONE, NONE,
    st_M, NONE, st_MUR, NONE, NONE,
    st_MURM, NONE, NONE, NONE, NONE,
    st_M, st_MURMU, NONE, NONE, NONE,
    st_M, NONE, st_MURMUR, NONE, NONE,
    st_MURM, NONE, NONE, st_MURMURS, NONE,
    st_M, NONE, NONE, NONE, NONE
};

int output_table[][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
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
            case 'm':
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            case 'u':
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
                break;
            case 'r':
                output = output_table[current_state][2];
                current_state = next_state_table[current_state][2];
                break;
            case 's':
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
        printf("Word detected\n");
    } else {
        printf("Word not detected\n");
    }

    return 0;
}