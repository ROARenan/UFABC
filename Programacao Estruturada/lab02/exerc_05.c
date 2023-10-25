// Renan Santana Ferreira 11202131332
// Ex 5 Matriz Transposta

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

void transp_matriz(int u[][1000], int c[][1000], int lin, int col){
    int i, j;
    printf("Vamos transpor a matriz \n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            c[j][i] = u[i][j];
        }
    }    

}

int lin, col;
int u[1000][1000], c[1000][1000];
int main() {

    printf("Entre com o numero de linhas: ");
    scanf("%d", &lin);
    printf("Entre com o numero de colunas: ");
    scanf("%d", &col);

    le_matriz(u, lin, col);

    printf("Matriz u:\n");
    escreve_matriz(u, lin, col);

    transp_matriz(u,c,lin,col);
    printf("Matriz c: \n");
    escreve_matriz(c,col,lin);
    return 0;
}
