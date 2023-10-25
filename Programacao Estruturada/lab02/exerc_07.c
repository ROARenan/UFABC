// Renan Santana Ferreira 11202131332
// Ex 7 Troca de lihas matriz


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

void troca_linhas(int u[][1000], int lin, int col){
    int i, j, x;

    //mesma ideia da troca de lugar de vetores
    printf("Quais linhas deseja trocar? \n");
    scanf("%d", &i);
    scanf("%d", &j); 
    for (int k = 0; k < col; k++) {
        x = u[i][k];
        u[i][k] = u[j][k];
        u[j][k] = x;
    }
    
}
int lin, col, u[1000][1000], x;
int main(){
    printf("Entre com o numero de linhas: ");
    scanf("%d", &lin);
    printf("Entre com o numero de colunas: ");
    scanf("%d", &col);
    le_matriz(u, lin, col);
    printf("Matriz u:\n");
    escreve_matriz(u, lin, col);
    troca_linhas(u, lin, col);
    escreve_matriz(u,lin,col);
    }