#include <stdio.h>

int main() {

    float user_input, pos_sum = 0, neg_sum = 0;
    int pos_count = 0, neg_count = 0;

    for (int i = 0; i < 15; i++) {
        printf("Enter a number: ");
        scanf("%f", &user_input);
        getchar();
        if (user_input > 0) { 
            pos_sum += user_input;
            pos_count++;
        } else if (user_input < 0) {
            neg_sum += user_input;
            neg_count++;
        } else {
            ;
        }
    }

    if (pos_count == 0) {
        printf("No positives input.\n");
    } else {
        printf("Average of positives: %f\n", pos_sum / pos_count);
    }

    if (neg_count == 0) {
        printf("No negatives input.\n");
    } else {
        printf("Average of negatives: %f\n", neg_sum / neg_count);
    }
    
    return 0;
}