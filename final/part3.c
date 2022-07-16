#include <stdio.h>
#include "rectstack.h"

int main() {
    FILE *in;
    if ((in = fopen("part3in", "r")) == NULL) {
        printf("Input file not found\n");
        return 1;
    }
    // print all non-overlapping rects
    load_rects(in);
    print_all();
    // print rectangle that overlaps with other rects the most
    return 0;
}