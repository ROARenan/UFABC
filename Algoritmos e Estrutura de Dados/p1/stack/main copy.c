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

    printf("Popped: ");
    element_print(stack_pop(stack));
    printf("\n");

    stack_print(stack);

    printf("Peeked: ");
    element_print(stack_peek(stack));
    printf("\n");

    stack_destroy(stack);

    return 0;
}