// Renan Santana Ferreira 11202131332
// Ex 4 Produto de vetor
#include <stdio.h>

void le_vetor(double l[], int n) {
    int i;
    printf("Escreva um a um o valor da lista\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &l[i]);
    }
}

int n;
double u[100], v[100], f[100];
int main() {
    int i;
    printf("Qual sera o tamanho das listas?\n");
    scanf("%d", &n);
    printf("Entre com a lista u\n");
    le_vetor(u, n);
    printf("Entre com a lista v\n");
    le_vetor(v, n);

    for (i = 0; i < n; i++) {
        f[i] = u[i] * v[i];
        printf("%.2lf \n", f[i]);
    }

    return 0;
}
