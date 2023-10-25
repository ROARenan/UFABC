// Renan Santana Ferreira 11202131332
// Ex 6 Matriz Simetrica

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

int check_matriz_simetria(int u[][1000], int lin, int col){
    int i, j, r, lin_i, col_j;
    printf("Vamos testar a simetria da matriz \n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            lin_i = (lin-i);
            col_j = (col-j);
            lin_i = (lin_i-1);
            col_j = (col_j-1);
            //printf("%d \n", lin_i);
            //printf("%d \n", col_j);
            if (u[i][j] == u[lin_i][col_j]){
                //printf("u[i][j] = %d \n", u[i][j]);
                //printf("u[lin_i][col_j] = %d \n", u[lin_i][col_j]);
                r = 1;
            }
            else{
                //printf("u[i][j] = %d \n", u[i][j]);
                //printf("u[lin_i][col_j] = %d \n", u[lin-i][col-j]);
                r = 0;
                break;
                break;
            }
        }
    }

    return r;
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
    x = check_matriz_simetria(u,lin,col);

    if (x == 1){
        printf("A matriz eh simetrica!");
    }
    else if (x == 0){
        printf("A nao matriz eh simetrica!");
    }
    return 0;
}
