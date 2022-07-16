#include <stdio.h>
#include <math.h>

int main() {

    float x, precision, current_term, taylor_sum = 0;
    int k = 1;

    do {
        printf("Enter a value in the range (0, 2]: ");
        scanf("%f", &x);
        printf("x = %f\n", x);
    } while (!(x <= 2 && x > 0));

    do {
        printf("Enter the minimum precision: ");
        scanf("%f", &precision);
        printf("precision = %f\n", precision);
    } while (precision > 1);

    do {
        current_term = (pow(-1, k+1) / k) * pow(x-1, k);
        taylor_sum += current_term;
        k += 1;
    } while (fabs(current_term) > precision);

    printf("Taylor series sum of ln(x) to given precision is %f\n", taylor_sum);
    
    return 0;
}