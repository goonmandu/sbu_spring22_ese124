#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    char input[100];
    printf("Enter a float, or # to exit: ");
    gets(input);
    while (1) {
        if (!strcmp(input, "#")) {
            break;
        } else {
            push(atof(input));
        }
        printf("Enter a float, or # to exit: ");
        gets(input);
    }
    sort_stack(0);
    print_entered();
}