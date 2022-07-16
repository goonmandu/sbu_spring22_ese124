#include <stdio.h>

int main() {
    int term;
    float sum = 0;

    printf("Number of terms in harmonic series: ");
    scanf("%d", &term);
    getchar();

    for(int i = 1; i <= term; i++) {
        sum += 1.0/i;
    }

    printf("Sum: %f\n", sum);
    return 0;
}