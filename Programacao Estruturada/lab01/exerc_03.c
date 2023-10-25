// Renan Santana Ferreira 11202131332
// Ex 3 Temperatura
#include <stdio.h>

int u;
float t, s;
int main() {
    printf("Digite 1 para C → F\n");
    printf("Digite 2 para F → C\n");
    scanf("%d",&u);
    printf("Voce escolheu %d",u);

    if (u==1){
        printf("\nDigite o valor em C\n");
        scanf("%f",&t);
        s = ((9.0/5.0)*t)+32;
        printf("Valor em F: %.2f", s);
    }
    else if (u==2){
        printf("\nDigite o valor em F\n");
        scanf("%f",&t);
        s = ((5.0/9.0)*(t-32));
        printf("Valor em C: %.2f", s);
    }
}
