// Renan Santana Ferreira 11202131332
// Ex 1 Numeros pares
#include <stdio.h>

int n;
int main() {
    int i;
    printf("Running \n");
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
        if (i%2 == 0){
            printf("%d eh par",i);
            printf("\n");
        }
    }
    return 0;
}
