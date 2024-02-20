#include "string_lib.h"

#include <stdio.h>
#include <stdlib.h>

String* string_create(char* data, int length) {
    String* str = malloc(sizeof(String));

    str->data = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        str->data[i] = data[i];
    }

    str->length = length;

    return str;
}

String* string_reverse(String str){
    String* back_str = malloc(sizeof(String));
    back_str->data = malloc(str.length * sizeof(char));

    int j = str.length;

    for (int i = 0; i < str.length; i++){
        back_str->data[i] = str.data[j];
        j--;
    }
}

void string_append(String *str1, String str2){
    
}

void string_destroy(String* str) {
    free(str->data);
    free(str);
}

void string_print(String* str) {
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}