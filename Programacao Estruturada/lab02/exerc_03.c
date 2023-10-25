// Renan Santana Ferreira 11202131332
// Ex 3 Ordena Vetor Mod

#include <stdio.h>

int check_max(int l[], int n, int start){
    int indice, x, r;
    for (indice = start; indice < n; indice++){
        if (indice == 0){
            x = l[indice];
            r = indice;
        }
        else if (x < l[indice]){
            x = l[indice];
            r = indice;
        }
        //printf("%d \n", x);
    }
    return r;
}

void le_vetor(int l[], int n){
    int i;
    printf("Escreva um a um o valor da lista\n");
    for (i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
}
void ordena_vetor(int l[], int n){
    int i, j, r;
    for (i=0; i<n; i++){
        r = check_max(l,n,i);
        j = l[i];
        l[i] = l[r];
        l[r] = j;
    }
}

int n, l[100], x, f;

int main() {
    printf("Entre com o tamanho da lista \n");
    scanf("%d", &n);
    le_vetor(l,n);
    printf("Vamos organizar essa bagaça \n");
    ordena_vetor(l,n);
    for (f=0;f<n;f++){
        printf("%d \n", l[f]);
    }
    return 0;
}
