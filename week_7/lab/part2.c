#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in, *out;
    char c, word[50];
    int w_idx = 0, c_idx = 0;

    if ((in = fopen("part2input", "r")) == NULL) {
        printf("Input file not found.\n");
        exit(1);
    }
    out = fopen("part2output", "w");

    while ((c = fgetc(in)) != EOF) {
        word[w_idx++] = c;
    }
    word[w_idx] = '\0';

    while (word[c_idx] != '\0') {
        if (word[c_idx] != word[c_idx+1]) {
            fputc(word[c_idx], out);
        }
        c_idx++;
    }
    
    fclose(in);
    fclose(out);
    return 0;
}