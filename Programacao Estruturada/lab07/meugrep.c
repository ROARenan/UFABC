#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *text;
    char *aux;
    int cont = 0, linha = 1, r = 0;
    if (argc < 2) {
        printf("Forneca os arquivos separados por espaco");
        return 1;
    }
    while (cont != '\n'){
        cont++;
    }

    for (int i = 1; i < argc; i++) {
        text = fopen(argv[i], "r");
        if (text == NULL) {
            printf("Erro ao abrir o arquivo %d",i);
        }

         while (fscanf(text, "%s", aux) != EOF) {
            printf("%s ",aux);
            if (aux == argv[0][r]){
                r++;
            }
            else{
                r = 0;
            }
            if (aux == '\n'){
                linha++;
            }
        }
        printf("\n");
        fclose(text);
    }

    return 0;
}
