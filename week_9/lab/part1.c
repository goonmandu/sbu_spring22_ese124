#include <stdio.h>

int main() {
    int fivebyfive[5][5], swapped[5][5], transpose[5][5], product[5][5];
    int temp[5], rows_to_sum[3];
    int sum = 0, triangle_sum = 0, scanned, swap_1, swap_2;
    FILE *in;

    if ((in = fopen("part1input", "r")) == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    printf("Generated 2D Array: \n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            fscanf(in, "%d", &scanned);
            fivebyfive[row][col] = scanned;
            printf("%d ", fivebyfive[row][col]);
        }
        printf("\n");
    }

    /* Problem A */
    printf("\nEnter your three rows (space separated): ");
    scanf("%d %d %d", &rows_to_sum[0], &rows_to_sum[1], &rows_to_sum[2]);
    getchar();

    for (int row = 0; row < 3; row++) {
        for (int idx = 0; idx < 5; idx++) {
            sum += fivebyfive[rows_to_sum[row]][idx];
        }
    }
    printf("Sum of given rows is %d.\n\n", sum);

    /* Problem B */
    printf("Upper triangle of original array:\n");
    for (int row = 0; row < 5; row++) {
        for (int idx = 0; idx < 5; idx++) {
            if (idx + row < 4) {
                printf("%d ", fivebyfive[row][idx]);
                triangle_sum += fivebyfive[row][idx];
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("Sum of upper triangle is %d.\n\n", triangle_sum);

    /* Problem C */
    printf("Enter two row numbers to swap (space separated): ");
    scanf("%d %d", &swap_1, &swap_2);
    getchar();
    
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            swapped[row][col] = fivebyfive[row][col];
        }
    }
    for (int idx = 0; idx < 5; idx++) {
        temp[idx] = fivebyfive[swap_1][idx];
        swapped[swap_1][idx] = swapped[swap_2][idx];
        swapped[swap_2][idx] = temp[idx];
    }
    printf("Swapped array:\n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            printf("%d ", swapped[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    /* Problem D */
    printf("Original multiplied by its transpose: \n");
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            transpose[col][row] = fivebyfive[row][col];
        }
    }
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            product[row][col] = transpose[row][col] * fivebyfive[row][col];
            printf("%d ", product[row][col]);
        }
        printf("\n");
    }

    return 0;
}