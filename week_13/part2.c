#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("How long is your string: ");
    scanf("%d", &size);
    char *str = (char *) malloc((size + 1) * sizeof(char));
    printf("Enter your string: ");
    scanf("%s", str);
    getchar();
    for (int i = size; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
    free(str);
    return 0;
}