#include <stdio.h>

#define MAX 100

int verificaPalavraNaFrase(char palavra[], char frase[]) {
    int i, j, k;
    int tamPalavra = 0;
    int tamFrase = 0;

    for (i = 0; palavra[i] != '\0'; i++) {
        tamPalavra++;
    }

    for (i = 0; frase[i] != '\0'; i++) {
        tamFrase++;
    }

    for (i = 0; i <= tamFrase - tamPalavra; i++) {
        int r = 1;
        for (j = 0; j < tamPalavra; j++) {
            if (frase[i + j] != palavra[j]) {
                r = 0;
                break;
            }
        }
        if (r) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char palavra[MAX];
    char frase[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Digite uma frase: ");
    getchar(); // Consumir o caractere de nova linha pendente
    fgets(frase, MAX, stdin);

    if (verificaPalavraNaFrase(palavra, frase)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
