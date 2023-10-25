// Renan Santana Ferreira 11202131332
// Ex 4 Soma Matriz

#include <stdio.h>

void le_matriz(int mat[][1000], int lin, int col){
    int i, j;
    printf("Escreva os valores um a um \n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void escreve_matriz(int mat[][1000], int lin, int col){
    int i, j;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void soma_matriz(int a[][1000], int b[][1000], int c[][1000], int lin, int col){
    int i, j;
    printf("Vamos somar as matrizes");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }    

}

int lin, col;
int u[1000][1000], v[1000][1000], c[1000][1000];
int main() {

    printf("Entre com o numero de linhas: ");
    scanf("%d", &lin);
    printf("Entre com o numero de colunas: ");
    scanf("%d", &col);

    le_matriz(u, lin, col);

    printf("Matriz u:\n");
    escreve_matriz(u, lin, col);

    le_matriz(v, lin, col);

    printf("Matriz v:\n");
    escreve_matriz(v, lin, col);

    soma_matriz(u,v,c,lin,col);
    printf("Matriz c: \n");
    escreve_matriz(c,lin,col);
    return 0;
}
