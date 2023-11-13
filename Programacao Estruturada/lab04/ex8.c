#include <stdio.h>
//#include <string.h>

char* strcat(char* a, char* b) {
    int i = 0, j = 0;

    while (a[i] != '\0') {
        i++;
    }

    while (b[j] != '\0') {
        a[i++] = b[j++];
    }

    a[i] = '\0';

    return a;
}

int main() {
    char a[50] = "Teste de frase, ";
    char b[50] = "para verificar o programa";

    printf("Nova string %s\n", strcat(a, b));

    return 0;
}