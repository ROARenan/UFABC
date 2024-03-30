#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "element.h"

typedef struct Stack Stack;

Stack* stack_create();
void stack_destroy(Stack* stack);
bool stack_push(Stack* stack, Element value);
Element stack_pop(Stack* stack);
Element stack_peek(Stack* stack);
bool stack_isEmpty(Stack* stack);
bool stack_is_full(Stack* stack);
int stack_size(Stack* stack);
void stack_print(Stack* stack);
Stack* stack_copy(Stack* s);

#endif