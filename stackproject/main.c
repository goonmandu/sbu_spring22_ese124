#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {

    push(4);
    push(92);
    pop();
    push(42);

    print_stack();
    return 0;
}
