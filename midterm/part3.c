#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    /* Declare all variables, and initialize if necessary */
    int bears = 0, cons = 0, vowels = 0;
    char scan[5], newscan;
    FILE *in;

    /* Check if file exists, and terminate if file is not found */
    if ((in = fopen("bearcounter", "r")) == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    /* Scan first four characters of the file */
    for (int i = 0; i < 4; i++) {
        scan[i] = fgetc(in);
    }
    scan[4] = '\0'; // Terminate manually for strcmp()
    
    /* Make all initially scanned chars lowercase. Then check if each character is a vowel, and update the counter accordingly */
    for (int i = 0; i < 4; i++) {
        scan[i] = tolower(scan[i]);
        if (isalpha(scan[i])) {
            if (scan[i] == 'a' || scan[i] == 'e' || scan[i] == 'i' || scan[i] == 'o' || scan[i] == 'u') {
                vowels++;
            } else {
                cons++;
            }
        }
    }

    /* Check if initial 4-char string is equal to "bear" and update the bears counter accordingly" */
    if (!strcmp(scan, "bear")) {
        bears++;
    }

    /* Read all characters until EOF */
    while ((newscan = tolower(fgetc(in))) != EOF) {
        /* Check if newly scanned character is a vowel, and update the counter accordingly */
        if (isalpha(newscan)) {
            if (newscan == 'a' || newscan == 'e' || newscan == 'i' || newscan == 'o' || newscan == 'u') {
                vowels++;
            } else {
                cons++;
            }
        }

        /* Shift each character left one element, then make the last character newscan, */
        scan[0] = scan[1];
        scan[1] = scan[2];
        scan[2] = scan[3];
        scan[3] = newscan;

        /* Check if newly formed 4-letter string is equal to "bear" and update bears counter accordingly*/
        if (!strcmp(scan, "bear")) {
            bears++;
        }
    }

    /* Print values to stdout */
    printf("Number of \"bear\"s: %d\n", bears);
    printf("Number of consonants: %d\n", cons);
    printf("Number of vowels: %d\n", vowels);

    return 0;
}