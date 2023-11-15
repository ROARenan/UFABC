#include <stdio.h>
#include <stdlib.h>

int* cartesiano(int **a, int na, int **b, int nb){
    int i, j, n, **v;
    n = na + nb;
    for (i=0;i<n;i++){
        for (j=0;j<2;j++){
            v[i] = malloc(n *  sizeof(int));
        }
    }
    for (i=0;i<n;i++){

    }
    
    return v;
}

int main(){
    int i;
    int *a = (int*) malloc(3 * sizeof(int));
    a[0] = 5;
    a[1] = 6;
    a[2] = 7;

    int *b = (int*) malloc(4 * sizeof(int));
    b[0] = 1;
    b[1] = 2;
    b[2] = 0;
    b[3] = 8;

    swap(&a, &b);
    for (i=0;i<3;i++){
        printf("%d, ",a[i]);
    }
    for (i=0;i<4;i++){
        printf("%d, ",b[i]);
    }
    free(a);
    free(b);
    return 0;
}