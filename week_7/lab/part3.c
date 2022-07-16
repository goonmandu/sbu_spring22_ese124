#include <stdio.h>

int main() {

    int terms, n = 9, sum = 0;

    printf("How many terms: ");
    scanf("%d", &terms);
    getchar();

    while (terms-- > 0) {
        sum += n;
        n *= 10;
        n += 9;
    }

    printf("Sum: %d\n", sum);

    return 0;
}