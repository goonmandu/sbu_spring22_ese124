/* Dynamic Memory Allocation */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int *arr;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n * 2; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < n * 2; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    printf("\n");
}