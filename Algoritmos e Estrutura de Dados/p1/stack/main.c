#include "stack.h"

#include <stdio.h>

int main() {
    Stack* stack = stack_create();

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);

    stack_print(stack);

    Stack *new = stack_copy(stack);

    stack_print(new);
    stack_destroy(stack);

    return 0;
}