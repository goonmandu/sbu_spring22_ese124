#include <stdio.h>
#include <math.h>

int main() {
    int term;
    float input, divby3, candidates[5], sums[3], delta[3];
    printf("Enter your float: ");
    scanf("%f", &input);
    getchar();

    divby3 = input / 3;
    term = (int) pow(divby3, -1);
    int idx = 0;

    for (int i = -2; i < 3; i++) {
        if (term + i > 0) {
            candidates[idx++] = term + i;
        }
    }
    /*
    for (int i = 0; i < 3; i++) {
        if (candidates[i]) {
            for (int j = 0; j < 3; i++) {
                sums[i] += candidates[i+j];
            }
        }
    }
    */
    for (int i = 0; i < 3; i++) {
        printf("%f, ", sums[i]);
    }

    return 0;
}