#include <stdio.h>
#include <stdlib.h>

char* strcat(char* a, char* b) {
    int i = 0, j = 0, k = 0;

    while (a[i] != '\0') {
        i++;
    }

    while (b[j] != '\0') {
        j++;
    }

    char * c = malloc((i + j + 1) * sizeof(char));
    
    i = 0;
    while (a[i] != '\0') {
        c[k] = a[i];
        i++;
        k++;
    }

    j = 0;
    while (b[j] != '\0') {
        c[k] = b[j];
        j++;
        k++;
    }

    c[k] = '\0';
    return c;
}

int main() {
    char a[] = "Frase ";
    char b[] = "Ola";

    printf("Nova string %s\n", strcat(a, b));
    printf("%s\n",a);

    return 0;
}