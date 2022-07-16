#include <stdio.h>
#include <math.h>

int main() {

    /* Declare all variables, and initialize if necessary */
    int n;
    float x, sum = 0, least;

    /* Take user inputs of number of terms and x value */
    printf("How many terms of ln(x): ");
    scanf("%d", &n);
    getchar();

    printf("x = ");
    scanf("%f", &x);
    getchar();

    /* Declare an array of size (n = number of terms) and fill it with given formula */
    float terms[n];
    for (int i = 1; i < n + 1; i++) {
        terms[i-1] = (pow(x - 1, i) / i) * pow(-1, i+1);
        sum += terms[i-1];
    }
    
    /* Print the terms in the array */
    for (int i = 0; i < n; i++) {
        printf("%f ", terms[i]);
    }

    /* Calculate least sum of three consecutive terms in array */
    least = terms[0] + terms[1] + terms[2];
    for (int i = 1; i < n - 3; i++) {
        if (terms[i] + terms[i+1] + terms[i+2] < least) {
            least = terms[i] + terms[i+1] + terms[i+2];
        }
    }

    /* Print values to stdout */
    printf("\nSum is %f\n", sum);
    printf("Least sum of three consecutive terms is %f\n", least);

    return 0;
}