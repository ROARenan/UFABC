#include <stdio.h>

int fatorial(int n){
    if (n>0){
        return n * fatorial (n-1);
    }
}

int binomio_newton(int n, int k){
    int x;
    if (n >= 0 || k >= 0){
        return binomio_newton(n-1,k-1)+ binomio_newton(n-1,k);
    };
    x = (fatorial(n)/(fatorial(k)*(fatorial(n)-fatorial(k))));
    return x;
}

int main(){
    int n, k;
    printf("Entre com o n\n");
    scanf("%d",&n);
    printf("Entre com o k\n");
    scanf("%d",&k);
    printf("%d\n",binomio_newton(n,k));
    return 0;
}