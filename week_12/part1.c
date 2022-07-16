#include <stdio.h>
#include <math.h>

double e_to_the_x(float num);
double x_squared(float num);
double x_cubed(float num);
float trapezoidal_integral(float left, float right, int points, double (*function) (float));


int main() {
    printf("%f\n", trapezoidal_integral(1, 9, 50, e_to_the_x));
    return 0;
}

/*
Square root = sqrt(x)
ln = log(x)
Exponential = pow(e, x)
Square = pow(x, 2)
Cube = pow(x, 3)

The % error is reduced as the number of discretization points increases,
because the diagonal side of the trapezoid gets closer and closer to the function graph.
*/

double e_to_the_x(float num) {
    return pow(2.7182818284, num);
}

double x_squared(float num) {
    return pow(num, 2);
}

double x_cubed(float num) {
    return pow(num, 3);
}

float trapezoidal_integral(float left, float right, int points, double (*function) (float)) {
    float trapezoid_area;
    float increment = fabs(left - right) / (points + 1);
    printf("%f ", increment);
    float x_position = left;
    float area = 0;
    for (int i = 0; i < points + 1; i++) {
        float left_y = function(x_position);
        x_position += increment;
        float right_y = function(x_position);
        trapezoid_area = increment * (left_y + right_y) / 2;
        printf("%f ", trapezoid_area);
        area += trapezoid_area;
        printf("%f\n", area);
    }
    return area;
}
