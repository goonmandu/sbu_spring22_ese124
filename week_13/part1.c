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
    for (int start = 0; start < size; start++) {
        for (int idx = start; idx < size; idx++) {
            printf("%c", *(str + idx));
        }
        printf("\n");
    }
    free(str);
    return 0;
}