#include <stdio.h>
#define ARR_LENGTH 50

int integer_in_array(int num, int array[]);

int main() {
    int number, existence;
    int arr[ARR_LENGTH] = {49, 65, 46, 96, 48, 58, 87, 16, 39, 99,
                           67, 42, 68, 59, 21, 53, 80, 23, 3, 57,
                           56, 35, 66, 47, 100, 98, 62, 95, 28, 1,
                           81, 43, 50, 7, 45, 15, 8, 92, 73, 70,
                           79, 10, 90, 37, 11, 31, 24, 72, 19, 29};  // 50 RNG, 1 - 100 inclusive
    /*
    for (int i = 0; i < ARR_LENGTH; i++) {
        arr[i] = i;
    }
    */
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);
        getchar();
        existence = integer_in_array(number, arr);
        if (existence >= 0) {
            printf("%d is in the array at index %d.\n", number, existence);
        } else {
            printf("%d is not in the array.\n", number);
        }
    }
    return 0;
}

int integer_in_array(int num, int array[]) {
    for (int i = 0; i < ARR_LENGTH; i++) {
        if (num == array[i]) {
            return i;
        }
    }
    return -1;
}