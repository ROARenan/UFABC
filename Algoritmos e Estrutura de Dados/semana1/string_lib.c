#include "string_lib.h"

#include <stdio.h>
#include <stdlib.h>

struct Matriz {
int rows;
int cols;
double* data;
};

String *string_create(char *data, int length)
{
    String *str = malloc(sizeof(String));

    str->data = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        str->data[i] = data[i];
    }

    str->length = length;

    return str;
}

String *string_reverse(String *str)
{
    String *back_str = malloc(sizeof(String));
    back_str->data = malloc(str->length * sizeof(char));

    int j = str->length - 1;

    for (int i = 0; i < str->length; i++)
    {
        back_str->data[i] = str->data[j];
        j--;
    }
    back_str->length = str->length;

    return back_str;
}

void string_append(String *str1, String *str2)
{
    str1->data = realloc(str1->data, (str1->length + str2->length) * sizeof(char));

    for (int i = 0; i < str2->length; i++)
    {
        str1->data[str1->length + i] = str2->data[i];
    }
    str1->length += str2->length;
}

void string_destroy(String *str)
{
    free(str->data);
    free(str);
}

void string_print(String *str)
{
    for (int i = 0; i < str->length; i++)
    {
        printf("%c", str->data[i]);
    }
    printf("\n");
}