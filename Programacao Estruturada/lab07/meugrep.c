#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *text;
    char aux;
    if (argc < 2) {
        printf("Forneca os arquivos separados por espaco");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        text = fopen(argv[i], "r");
        if (text == NULL) {
            printf("Erro ao abrir o arquivo %d",i);
        }

         while (fscanf(text, "%c", &aux) != EOF) {
            printf("%c",aux);
        }
        printf("\n");
        fclose(text);
    }

    return 0;
}
