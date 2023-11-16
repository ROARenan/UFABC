#include <stdio.h>
#include <stdlib.h>

int ** matriz_le(int n, int m) {
    int i = 0, j=0;
    int ** mat = malloc(n*sizeof(int));
    for (i=0;i<m;i++){
        mat[i] = malloc(m * sizeof(int));
    }
    printf("Entre com os dados\n");
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

void matriz_print(int ** mat, int n, int m){
    int i = 0, j=0;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

void matriz_free(int ** mat, int n, int m){
    for (int i=0;i<n;i++){
        free(mat[i]);
    }
    free(mat);
}

int n,m;
int main() {
    scanf("%d",&n);
    scanf("%d",&m);
    int **mat = matriz_le(n,m);
    matriz_print(mat,n,m);
    matriz_free(mat,n,m);
    return 0;
}