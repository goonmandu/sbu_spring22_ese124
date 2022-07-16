#include <stdio.h>
#include <stdlib.h>
#define INPUT_FILE "2-input"
#define OUTPUT_FILE "2-1-output"

int main() {
    FILE *in, *out;
    char ltr1, ltr2;

    if ((in = fopen(INPUT_FILE, "r")) == NULL) {
        printf("No input file");
        exit(1);
    }
    if ((out = fopen(OUTPUT_FILE, "w")) == NULL) {
        printf("No output file");
        exit(1);
    }

    ltr1 = fgetc(in);
    ltr2 = fgetc(in);

    while (1) {
        if (ltr1 == '+' && ltr2 == '+') {
            fputs("(INCREMENT)", out);
            ltr1 = ltr2;
            ltr2 = fgetc(in);
        } else if (ltr1 == '-' && ltr2 == '-') {
            fputs("(DECREMENT)", out);
            ltr1 = ltr2;
            ltr2 = fgetc(in);
        } else if (ltr1 == '+' && ltr2 == '=') {
            fputs("(ADD ASSIGN)", out);
            ltr1 = ltr2;
            ltr2 = fgetc(in);
        } else if (ltr1 == '*' && ltr2 == '=') {
            fputs("(MULTIPLY ASSIGN)", out);
            ltr1 = ltr2;
            ltr2 = fgetc(in);
        } else if ((ltr1 == '_') || (ltr1 >= 65 && ltr1 <= 90) || (ltr1 >= 48 && ltr1 <= 57)) {
            fputc(ltr1, out);
        } else if (ltr1 >= 97 && ltr1 <= 122) {
            fputc(ltr1 - 32, out);
        } else {
            switch (ltr1) {
                case '+': fputs("PLUS ", out); break;
                case '-': fputs("MINUS ", out); break;
                case '*': fputs("MULTIPLY ", out); break;
                case '/': fputs("DIVIDE ", out); break;
                case '%': fputs("MODULO ", out); break;
                case '@': fputs("AT ", out); break;
                case '&': fputs("BITWISE AND ", out); break;
                case '^': fputs("BITWISE XOR ", out); break;
                case '.': fputs("DOT ", out); break;
                case ',': fputs("COMMA ", out); break;
                case ';': fputs("SEMICOLON ", out); break;
                case ':': fputs("COLON ", out); break;
                case '=': fputs("ASSIGN ", out); break;
            }
        }
        if (ltr2 == EOF) {
            break;
        }
        ltr1 = ltr2;
        ltr2 = fgetc(in);
    }
    fclose(in);
    fclose(out);

    return 0;
}