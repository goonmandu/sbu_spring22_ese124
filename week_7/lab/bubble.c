#include <stdio.h>
#include <stdlib.h>
#define ARR_LENGTH 30

int main() {

    FILE *in, *out;
    int arr[ARR_LENGTH];
    int sorted = 0, temp, idx = 0;

    if ((in = fopen("bubbleinput", "r")) == NULL) {
        printf("Input file not found.\n");
        exit(1);
    }
    out = fopen("bubbleoutput", "w");

    int num;
    while(fscanf(in, "%d", &num) > 0) {
        arr[idx++] = num;
    }

    while (sorted < ARR_LENGTH - 1) {
        sorted = 0;
        for (int i = 0; i < ARR_LENGTH - 1; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                sorted++;
            }
        }
    }

    for (int i = 0; i < ARR_LENGTH; i++) {
        fprintf(out, "%d ", arr[i]);
    }

    return 0;
}