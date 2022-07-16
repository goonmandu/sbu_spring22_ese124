#include <stdio.h>
#define INIT_MAX 100

typedef struct Rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
} Rectangle;

void store(int, int, int, int);
int check_overlap(int, int);
void display(int);
void _remove(int);
int num_of_rectangles(void);
void load_rects(FILE *);
void display_all(void);
void print_all(void);