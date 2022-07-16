#include <stdio.h>

int my_is_upper(char c);
int my_is_lower(char c);
int my_isalpha(char c);
int my_isdigit(char c);
int my_alnum(char c);
char my_to_upper(char c);
char my_to_lower(char c);
void check_functions(char c);

int main() {
    char input;

    for (int i = 0; i < 3; i++) {
        printf("Enter a character to check: ");
        scanf("%c", &input);
        getchar();

        check_functions(input);
        printf("\n");
    }

    return 0;
}


/* Function initializations */

int my_is_upper(char c) {
    if ('A' <= c && 'Z' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_is_lower(char c) {
    if ('a' <= c && 'z' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_isalpha(char c) {
    if (my_is_upper(c) || my_is_lower(c)) {
        return 1;
    } else {
        return 0;
    }
}

int my_isdigit(char c) {
    if ('0' <= c && '9' >= c) {
        return 1;
    } else {
        return 0;
    }
}

int my_alnum(char c) {
    if (my_isalpha(c) || my_isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

char my_to_upper(char c) {
    if (my_is_lower(c)) {
        return c - 32;
    } else {
        return c;
    }
}

char my_to_lower(char c) {
    if (my_is_upper(c)) {
        return c + 32;
    } else {
        return c;
    }
}

void check_functions(char c) {
    printf("Is uppercase? %d\n", my_is_upper(c));
    printf("Is lowercase? %d\n", my_is_lower(c));
    printf("Is alphabet?  %d\n", my_isalpha(c));
    printf("Is digit?     %d\n", my_isdigit(c));
    printf("Is alphanum?  %d\n", my_alnum(c));
    printf("Uppercased:   %c\n", my_to_upper(c));
    printf("Lowercased?   %c\n", my_to_lower(c));
}