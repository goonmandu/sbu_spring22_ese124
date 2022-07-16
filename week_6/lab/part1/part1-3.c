#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in, *out;
    char ltr;

    if ((in = fopen("1-1-input", "r")) == NULL) {
        printf("No input file\n");
        exit(1);
    }

    if ((out = fopen("1-3-output", "w")) == NULL) {
        printf("No output file\n");
        exit(1);
    }

    while ((ltr = fgetc(in)) != EOF) {
        if ((ltr == '_') || (ltr >= 65 && ltr <= 90) || (ltr >= 48 && ltr <= 57)) {
            fputc(ltr, out);
        } else if (ltr >= 97 && ltr <= 122) {
            fputc(ltr - 32, out);
        }
    }

    fclose(in);
    fclose(out);

    return 0;

}