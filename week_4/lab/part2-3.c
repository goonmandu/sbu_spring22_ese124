#include <stdio.h>
#include <ctype.h>

int main() {

    char ltr;

    while (1) {
        printf("Enter a letter: ");
        scanf("%c", &ltr);
        getchar();

        if (ltr == '#') {
            break;
        }
        
        ltr = tolower(ltr);
        if (ltr == 'a' || ltr == 'e' || ltr == 'i' || ltr == 'o' || ltr == 'u') {
            printf("Entered letter is a vowel.\n\n");
        } else {
            printf("Entered letter is a consonant.\n\n");
        }
    }

    return 0;
}