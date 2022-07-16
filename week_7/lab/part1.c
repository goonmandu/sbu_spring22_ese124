#include <stdio.h>
#include <ctype.h>
#define ARR_LENGTH 15

int main() {

    char arr[ARR_LENGTH] = {'g', 'a', 2, 'b', 3, 'c', 4, 'd', 5, 'e', 'v', 'f', 'h', 'i', 'f'};
    int num_alpha = 0, num_other = 0;
    for (int i = 0; i < ARR_LENGTH; i++) {
        if (isalpha(arr[i])) {
            num_alpha++;
        } else {
            num_other++;
        }
    }
    printf("%dALP, %dETC\n", num_alpha, num_other);
    if (num_alpha >= 2 * num_other) {
        printf("The array is sparce.\n");
    } else {
        printf("The array is not sparce.\n");
    }

    return 0;
}