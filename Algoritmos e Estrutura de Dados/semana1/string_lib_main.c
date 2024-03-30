#include <stdio.h>
#include "string_lib.h"

int main(void) {
    // Criando duas strings
    String* str1 = string_create("Hello", 5);
    String* str2 = string_create(" World!", 7);

    // Imprimindo as strings originais
    printf("String 1: ");
    string_print(str1);
    printf("String 2: ");
    string_print(str2);

    // Revertendo a primeira string e imprimindo
    String* reversed_str = string_reverse(str1);
    printf("String 1 invertida: ");
    string_print(reversed_str);

    // Concatenando as duas strings e imprimindo
    string_append(str1, str2);
    printf("String concatenada: ");
    string_print(str1);

    // Destruindo as strings
    string_destroy(str1);
    string_destroy(str2);
    string_destroy(reversed_str);

    return 0;
}
