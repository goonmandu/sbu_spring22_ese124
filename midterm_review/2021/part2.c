#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    int thes = 0;
    char scan[4], newscan;
    FILE *in;
    if ((in = fopen("thecounter", "r")) == NULL) {
        printf("Input file not found.\n");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        scan[i] = fgetc(in);
    }
    scan[3] = '\0';
    for (int i = 0; i < 3; i++) {
        scan[i] = tolower(scan[i]);
    }
    if (!strcmp(scan, "the")) {
        thes++;
    }
    while ((newscan = fgetc(in)) != EOF) {
        scan[0] = scan[1];
        scan[1] = scan[2];
        scan[2] = newscan;
        if (!strcmp(scan, "the")) {
            thes++;
        }
    }
    printf("Number of \"the\"s: %d\n", thes);
    return 0;
}