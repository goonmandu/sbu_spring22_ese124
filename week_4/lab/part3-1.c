#include <stdio.h>
#include <math.h>

int main() {

    float x, precision, current_term, taylor_sum = 1;
    int exponent = 1;

    do {
        printf("Enter a value within the range (-1, 1): ");
        scanf("%f", &x);
        printf("x = %f\n", x);
    } while (!(x < 1 && x > -1));

    do {
        printf("Enter the minimum precision: ");
        scanf("%f", &precision);
        printf("precision = %f\n", precision);
    } while (precision > 1);

    do {
        current_term = pow(x, exponent);
        taylor_sum += current_term;
        exponent += 1;
    } while (fabs(current_term) > precision);

    printf("Taylor series sum of 1/(1-x) to given precision is %f\n", taylor_sum);
    
    return 0;
}