#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Informe o nome do arquivo.\n");
        return 1;
    }

    FILE *text;
    int car = 0;
    int cont = 0;
    char aux;

    text = fopen(argv[1], "r");
    if (text == NULL) {
        printf("Erro no carregamento do arquivo\n");
        return 1;
    } else {
        printf("Arquivo aberto para leitura\n");
    }

    while (fscanf(text, "%c", &aux) != EOF) {
        if (aux == ' ' || aux == '\n') {
            if (car > 0) {
                cont++;
                car = 0;
            }
        } else {
            car++;
        }
    }

    if (car > 0) {
        cont++;
    }

    printf("Temos %d palavras\n", cont);

    fclose(text);
    return 0;
}
