#include <stdio.h>
#include "rectstack.h"

int next = 0;
Rectangle *rectangles;

void store(int _x1, int _y1, int _x2, int _y2) {
    rectangles[next].x1 = _x1;
    rectangles[next].y1 = _y1;
    rectangles[next].x2 = _x2;
    rectangles[next].y2 = _y2;
}

int check_overlap(int r1, int r2) {
    if ((rectangles[r1].x1 < rectangles[r2].x1 && rectangles[r1].x2 > rectangles[r2].x1 && rectangles[r1].y1 < rectangles[r2].y1 && rectangles[r1].y2 > rectangles[r2].y1) ||
    (rectangles[r1].x1 < rectangles[r2].x2 && rectangles[r1].x2 > rectangles[r2].x2 && rectangles[r1].y1 < rectangles[r2].y2 && rectangles[r1].y2 > rectangles[r2].y2)) {
        return 1;
    } else {
        return 0;
    }
}   

void display(int idx) {
    printf("Coordinates of rectangle %d:\n (%d, %d)\n (%d, %d)\n (%d, %d)\n (%d, %d)\n", idx, rectangles[idx].x1, rectangles[idx].y1, rectangles[idx].x1, rectangles[idx].y2, rectangles[idx].x2, rectangles[idx].y2, rectangles[idx].y2, rectangles[idx].x1);
}

void _remove(int idx) {
    next--;
    for (int i = idx; i < next; i++) {
        rectangles[idx] = rectangles[idx+1];
    }
}

int num_of_rectangles() {
    return next;
}

void load_rects(FILE *fptr) {
    while (fscanf(fptr, "%d %d %d %d", &rectangles[next].x1, &rectangles[next].y1, &rectangles[next].x2, &rectangles[next].y2) != EOF) {
        next++;
    }
}

void print_all() {
    for (int i = 0; i < next; i++) {
        display(i);
    }
}