#include <stdio.h>
#define MAX 1000

typedef struct
{
    int mat[MAX][MAX];
}Matriz;

Matriz matriz_le(int n){
    Matriz m;
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", m.mat[i][j]);
        }
    }
    return  m;
}

Matriz matriz_multiplica(Matriz a, Matriz b) {
    Matriz c;
    int i, j, n;
    n = sizeof(a.mat)/sizeof(a.mat[0]);
    printf("%d", n);
    for (i = 0; i < sizeof(a.mat[MAX][MAX]); i ++){
        
    }
    return c;
}

int main() {

    return 0;
}