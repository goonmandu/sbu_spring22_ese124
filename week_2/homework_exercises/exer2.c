#include <stdio.h>
#include <ctype.h>

int main() {

    char ltr;
    scanf("%c", &ltr);

    if (tolower(ltr) == 'a' || tolower(ltr) == 'e' || tolower(ltr) == 'i' || tolower(ltr) == 'o' || tolower(ltr) == 'u') {
        printf("Entered letter is a vowel.\n");
    } else {
        printf("Entered letter is not a vowel.\n");
    }

    printf("%d\n", (int)ltr);
    return 0;

}