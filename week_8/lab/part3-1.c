#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_OF_INSTR 100

bool startswith(const char *str, const char *start) {
    return strncmp(start, str, strlen(start)) == 0;
}

int main() {
    FILE *in, *out;
    char c, numstr[10], inst[100], instructions[NUM_OF_INSTR][100];
    float x_pos = 0, y_pos = 0;

    if ((in = fopen("part3-1-in", "r")) == NULL) {
        printf("No input file");
        exit(1);
    }
    if ((out = fopen("part3-1-out", "w")) == NULL) {
        printf("No output file");
        exit(1);
    }

    while ((c = fgetc(in)) != EOF) {
        printf("%c", c);
    }

    /*
    int i_idx = 0, c_idx = 0;
    while ((c = fgetc(in)) != EOF) {
        if (c == '\n') {
            instructions[i_idx][c_idx] = '\0';
            c_idx = 0;
            i_idx++;
        } else {
            instructions[i_idx][c_idx++] = c;
        }
    }
    */


   /*
    for (int i = 0; i < NUM_OF_INSTR; i++) {
        printf("%s\n", instructions[i]);
        if (startswith(instructions[i], "LEFT")) {
            printf("%c\n", instructions[i][strlen("LEFT")+2]);
            x_pos += strtof(numstr, NULL);
        }
    }

    printf("%f\n", x_pos);
    */

    return 0;
}