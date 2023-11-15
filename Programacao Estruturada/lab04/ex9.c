#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* revert(char* s) {
    int len = strlen(s);
    char* rev = malloc(len + 1);
    rev[len] = '\0';
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - i - 1];
    }
    return rev;
}

int main() {
    char s[] = "hello world";
    char* ns = revert(s);
    printf("%s\n", ns);
    free(ns);
    return 0;
}