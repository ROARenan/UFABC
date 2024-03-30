#include "dec_to_bin.h"

#include <stdlib.h>
#include <stdio.h>

char *decToBin(unsigned int n)
{
    Stack *stack = binaryStack(n);
    char *binaryStr = stackToString(stack);

    stack_destroy(stack);
    return binaryStr;
}

// new functions

Stack *binaryStack(unsigned int n)
{
    Stack *s = stack_create(divs_by_two(n));
    int hold = n;
    int resto;
    while (hold != 1)
    {
        resto = hold % 2;
        hold = hold / 2;
        if (hold < 2)
        {
            hold = 2;
        }
        stack_push(s, resto);
    }

    stack_print(s);

    return s;
}

char *stackToString(Stack *s)
{
}