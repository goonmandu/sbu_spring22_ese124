#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NONE 0
#define st_1A 1
#define st_2A 2
#define st_3A 3
#define st_X 4
#define st_INIT NONE

int next_state_table[][2] = {
    st_1A, NONE,
    st_2A, st_1A,
    st_3A, st_2A,
    st_X, st_3A,
    st_X, st_X
};

int output_table[][2] = {
    0, 0,
    0, 0,
    1, 0,
    0, 1,
    0, 0
};



int main() {

    char user_input[100];
    int current_state = st_INIT;
    int output;
    int saw_frog = 0;

    printf("Enter a string: ");
    scanf("%s", user_input);
    getchar();

    for (int idx = 0; idx < strlen(user_input); idx++) {
        switch (tolower(user_input[idx])) {
            case 'a':
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            default:
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
        }
        printf("%c/%d/%d\n", tolower(user_input[idx]), output, saw_frog);
    }

    if (output) {
        printf("There are exactly three A's.\n");
    } else {
        printf("There are not exactly three A's.\n");
    }
    
    return 0;
}