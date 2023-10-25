#include <stdio.h>
#define MAX 1000

int is_upper(char letra) {
    return (letra >= 'A' && letra <= 'Z');
}

int is_lower(char letra) {
    return (letra >= 'a' && letra <= 'z');
}

char toggle_case(char letra) {
    if (is_upper(letra)) {
        return letra + 32; // Converter de maiúsculo para minúsculo na tabela ASCII
    } else if (is_lower(letra)) {
        return letra - 32; // Converter de minúsculo para maiúsculo na tabela ASCII
    }
    return letra; // Não é uma letra, retorna sem alterações
}

int main() {
    char frase[MAX];

    printf("Digite uma frase: ");
    fgets(frase, MAX, stdin);

    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = toggle_case(frase[i]);
    }

    printf("Frase convertida: %s", frase);

    return 0;
}
