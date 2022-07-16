#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int top = 0;
char stack[SIZE][50];

int isfull() {
    return (top == SIZE) ? 1 : 0;
}

int isempty() {
    return (top == 0) ? 1 : 0;
}

char *top_num() {
    if (!isempty()) {
        return (stack[top-1]);
    } else {
        printf("ERR: Tried to read an empty stack.\n");
        exit(1);
    }
}

void push(char *string) {
    if (!isfull()) {
        strcpy(stack[top++], string);
    } else {
        printf("ERR: Tried to push() to a full stack.\n");
        exit(1);
    }
}

char *pop() {
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
            printf("%s, ", stack[i]);
        } else {
            printf("%s", stack[i]);
        }
    }
    printf("}\n");
}

char *delete_first_letters(char *word, int letters) {
    int final_len = 0;
    for (int idx = 0; idx < strlen(word) - letters; idx++) {
        word[idx] = word[idx+letters];
        final_len++;
    }
    word[final_len] = '\0';
    return word;
}

int main() {
    char input[56], cmd[5], arg[50];
    printf("Commands: pus, pop, exi\n\n");
    while (1) {
        printf("Enter a command: ");
        gets(input);
        strncpy(cmd, &input[0], 3);
        if (!strcmp("pop", cmd)) {
            pop();
            print_stack();
            continue;
        } else if (!strcmp("exi", cmd)) {
            return 0;
        }
        strcpy(arg, delete_first_letters(input, 4));
        if (!strcmp("pus", cmd)) {
            push(arg);
        } else {
            printf("Invalid command.\n");
        }
        print_stack();
    } 
    return 0;
}