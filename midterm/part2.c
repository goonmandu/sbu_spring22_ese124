#include <stdio.h>

int main() {

    /* Declare all variables, and initialize if necessary */
    float neg[100], pos[100], scanned, n_sum = 0, p_sum = 0;
    FILE *in;

    /* Check if file exists, and terminate if file is not found */
    if ((in = fopen("decimals.txt", "r")) == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    /* Scan each number in the input file, and append them to either array based on sign*/
    int p_idx = 0, n_idx = 0;
    while (fscanf(in, "%f", &scanned) != EOF) {
        if (scanned < 0) {
            neg[n_idx++] = scanned;
        } else if (scanned > 0) {
            pos[p_idx++] = scanned;
        }
    }

    /* Count number of elements in each array */
    for (int i = 0; i < n_idx; i++) {
        n_sum += neg[i];
    }

    for (int i = 0; i < p_idx; i++) {
        p_sum += pos[i];
    }

    /* Print number of positives and negatives to stdout */
    printf("Sum of positives: %f\n", p_sum);
    printf("Sum of negatives: %f\n", n_sum);

    return 0;
}