#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define SIZE 100

static int stack[SIZE];
static int top = 0;

int isfull() {
    return (top == SIZE) ? 1 : 0;
}

int isempty() {
    return (top == 0) ? 1 : 0;
}

int top_num() {
    if (!isempty()) {
        return (stack[top-1]);
    } else {
        printf("ERR: Tried to read an empty stack.\n");
        exit(1);
    }
}

void push(int num) {
    if (!isfull()) {
        stack[top++] = num;
    } else {
        printf("ERR: Tried to push() to a full stack.\n");
        exit(1);
    }
}

int pop() {
    if (!isempty()) {
        top--;
        return stack[top];
    } else {
        printf("ERR: Tried to pop() an empty stack.\n");
        exit(1);
    }
}

void print_stack() {
    printf("Stack: {");
    for (int i = 0; i < top; i++) {
        if (i != top - 1) {
            printf("%d, ", stack[i]);
        } else {
            printf("%d", stack[i]);
        }
    }
    printf("}\n");
    printf("Top number: %d\n", top_num());
    printf("Empty? %d\n", isempty());
    printf("Full? %d\n", isfull());
}