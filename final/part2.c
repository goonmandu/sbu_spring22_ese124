#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NONE 0
#define st_G 1
#define st_GA 2
#define st_GAG 3
#define st_INIT NONE;

int next_state_table[][3] = {
    st_G, NONE, NONE,
    NONE, st_GA, NONE,
    st_GAG, NONE, NONE,
    NONE, st_GA, NONE
};

int output_table[][3] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 1, 0
};

int main() {
    FILE *in;
    int current_state = st_INIT;
    int output;
    int gaga_counter = 0;
    char c;
    if ((in = fopen("part2in", "r")) == NULL) {
        printf("Input file not found\n");
        return 1;
    }

    while ((c = fgetc(in)) != EOF) {
        printf("%c\n", c);
        switch (tolower(c)) {
            case 'g':
                output = output_table[current_state][0];
                current_state = next_state_table[current_state][0];
                break;
            case 'a':
                output = output_table[current_state][1];
                current_state = next_state_table[current_state][1];
                break;
            default:
                output = output_table[current_state][2];
                current_state = next_state_table[current_state][2];
        }

        if (output) {
            gaga_counter++;
        }
    }

    printf("The string \"gaga\" has been seen %d times.\n", gaga_counter);

    return 0;
}