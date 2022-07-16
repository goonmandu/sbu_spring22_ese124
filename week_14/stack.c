#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define SIZE 100

static float stack[SIZE];
static float *entered;
static int top = 0;

int isfull() {
    return (top == SIZE) ? 1 : 0;
}

int isempty() {
    return (top == 0) ? 1 : 0;
}

float top_num() {
    if (!isempty()) {
        return (stack[top-1]);
    } else {
        printf("ERR: Tried to read an empty stack.\n");
        exit(1);
    }
}

void push(float num) {
    if (!isfull()) {
        stack[top++] = num;
    } else {
        printf("ERR: Tried to push() to a full stack.\n");
        exit(1);
    }
}

float pop() {
    if (!isempty()) {
        top--;
        return stack[top];
    } else {
        printf("ERR: Tried to pop() an empty stack.\n");
        exit(1);
    }
}

void sort_stack(int ord) {
    entered = (float *) realloc(entered, (top - 1) * sizeof(float));
    for (int idx = 0; idx < top; idx++) {
        entered[idx] = stack[idx];
    }
    int sorted;
    if (!ord) {
        while (sorted < top - 1) {
            sorted = 0;
            for (int i = 0; i < top - 1; i++) {
                if (entered[i] > entered[i+1]) {
                    float temp = entered[i];
                    entered[i] = entered[i+1];
                    entered[i+1] = temp;
                } else {
                    sorted++;
                }
            }
        }
    } else {
        while (sorted < top - 1) {
            sorted = 0;
            for (int i = 0; i < top - 1; i++) {
                if (entered[i] > entered[i+1]) {
                    float temp = entered[i];
                    entered[i] = entered[i+1];
                    entered[i+1] = temp;
                } else {
                    sorted++;
                }
            }
        }
    }
}

void print_stack() {
    printf("Stack: {");
    for (int i = 0; i < top; i++) {
        if (i != top - 1) {
            printf("%f, ", stack[i]);
        } else {
            printf("%f", stack[i]);
        }
    }
    printf("}\n");
    // printf("Top number: %f\n", top_num());
    printf("Empty? %d\n", isempty());
    printf("Full? %d\n", isfull());
}

void print_entered() {
    for (int i = 0; i < top; i++) {
        if (i != top - 1) {
            printf("%f, ", entered[i]);
        } else {
            printf("%f", entered[i]);
        }
    }
    printf("\n");
}