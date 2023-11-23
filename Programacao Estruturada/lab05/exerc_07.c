#include <stdio.h>

int fatorial(int n){
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}

int binomio_newton(int n, int k){
    if (n >= 0 && k >= 0 && n >= k) {
        return fatorial(n) / (fatorial(k) * fatorial(n - k));
    } else {
        return 0;  // Tratar casos inválidos
    }
}

int main(){
    int n, k;
    printf("Entre com o n\n");
    scanf("%d", &n);
    printf("Entre com o k\n");
    scanf("%d", &k);

    if (n < k) {
        printf("Erro: n deve ser maior ou igual a k.\n");
    } else {
        printf("%d\n", binomio_newton(n, k));
    }

    return 0;
}
