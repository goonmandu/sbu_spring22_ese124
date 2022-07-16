#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *in, *out;
    char ltr;

    if ((in = fopen("1-1-input", "r")) == NULL) {
        printf("No input file\n");
        exit(1);
    }

    if ((out = fopen("1-2-output", "w")) == NULL) {
        printf("No output file\n");
        exit(1);
    }

    while ((ltr = fgetc(in)) != EOF) {
        if (isalpha(ltr) || (ltr >= 48 && ltr <= 57) || (ltr == '_'))
            fputc(ltr, out);
    }

    fclose(in);
    fclose(out);

    return 0;

}