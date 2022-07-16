#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char char1, char2, arg[256];
    int numbers[100];
    FILE *in, *out;

    if ((in = fopen("part2-1_in", "r")) == NULL) {
        printf("No input file");
        exit(1);
    }
    if ((out = fopen("part2-1_out", "w")) == NULL) {
        printf("No output file");
        exit(1);
    }

    // while (fgets(a))

    return 0;
}