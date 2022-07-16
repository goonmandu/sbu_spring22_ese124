#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in, *out;
    char ltr;

    if ((in = fopen("1-1-input", "r")) == NULL) {
        printf("No input file");
        exit(1);
    }
    if ((out = fopen("1-1-output", "w")) == NULL) {
        printf("No output file");
        exit(1);
    }
    while ((ltr = fgetc(in)) != EOF) {
        fputc(ltr, out);
    }

    fclose(in);
    fclose(out);

    return 0;

}