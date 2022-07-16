#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

double *maxdouble(double *arr);

int main() {
    int size = 10;
    double double_array[10] = {82.32, 6.77, 66.4, 57.83, 94.4, 66, 89.97, 59, 21.73, 47.11};
    printf("%lf\n", *(maxdouble(double_array)));
    return 0;
}

double *maxdouble(double *arr) {
    double maximum = arr[0];
    for (int i = 1; i < SIZE; i++) {
        if (maximum < arr[i]) {
            maximum = arr[i];
        }
    }
    double *doubleptr = &maximum;
    return doubleptr;
}