/* KINDA GAVE UP HALFWAY */
/* WE WERE NOT TAUGHT THIS STUFF */
/* Explanations in comments to document what I at least tried to do */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 64

/* Queue to keep track of nodes */
int top = 0;
int q[MAX];

/* Functions I tried to implement */
void sanity_check(char arr[64]);
void solver(int x, int y);
void push(int cell);
int pop();
int get_top(int *q);
int is_empty(int *q);
int is_full(int *q);
void clear();
void print_queue();
void nodes();

/* Extra globals for functions to use */
int start[2] = {1, 1};
int possible_cells[4] = {-1, -1, -1, -1};
int num_nodes = 0;
char maze[64];

int main() {
    FILE *in;
    if ((in = fopen("part2-2-in.txt", "r")) == NULL) {
        printf("No input file.");
        return 1;
    }
    char tile;
    int areas[MAX];
    /* Stores maze in 2D array, and calculates the number of free spaces, or "nodes" in the maze */
    for (int cell = 0; cell < 64; cell++) {
        tile = fgetc(in);
        maze[cell] = tile;
        if (tile == ' ') {
            num_nodes++;
        }
        fgetc(in);
    }
    printf("\n");
    sanity_check(maze);
    return 0;
}

/* Sanity check to see if the maze got copied in correctly */
void sanity_check(char arr[64]) {
    for (int cell = 0; cell < 64; cell++) {
        printf("%c, ", maze[cell]);
        /*
        if (cell % 8 == 7) {
            printf("\n");
        }
        */
    }
    printf("\n");
}

/* Main solver method. You can see I gave up halfway */
void solver(int x, int y) {
    int queue_idx = 0;
    push(x * 8 + y);
    int *visited = (int *) malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }
    while (!is_empty(q)) {
        int node = q[queue_idx];

    }
}

/* Miscellaneous functions for the queue */
void push(int cell) {
    q[top] = cell;
    top++;
}

int pop(int *q) {
    return q[top--];
}

int get_top(int *q) {
    return q[top];
}

int is_empty(int *q) {
    if (!top) {
        return 1;
    } else {
        return 0;
    }
}

int is_full(int *q) {
    if (top == MAX) {
        return 1;
    } else {
        return 0;
    }
}

void clear() {
    top = 0;
}
/*
void print_queue() {
    for (int i = 0; i < top; i++) {
        printf("(%d, %d)\n", x[i], y[i]);
    }
}
*/

/* Determine which nodes are adjacent to each node, and store them in a global array vairable for function access */
void nodes(int cell) {
    if (!(0 <= cell && cell <= 7) && cell - 8) {
        possible_cells[0] = cell - 8;
    }
    if (!(56 <= cell && cell <= 63)) {
        possible_cells[1] = cell + 8;
    }
    if (cell % 8) {
        possible_cells[2] = cell - 1;
    }
    if (cell % 8 != 7)
    possible_cells[3] = cell + 1;
}