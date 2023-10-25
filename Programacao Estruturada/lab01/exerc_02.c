// Renan Santana Ferreira 11202131332
// Ex 2 Numeros primos
#include <stdio.h>

int n,i;
int main() {
    printf("Ate qual numero deseja ir: ");
    scanf("%d", &n);
    for ( i = 1; i <= n; i++) {
        int divs = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                divs++;
            }
        }
        if (divs == 2) {
            printf("%d eh primo\n", i);
        }
    }

    return 0;
}
