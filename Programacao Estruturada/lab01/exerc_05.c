// Renan Santana Ferreira 11202131332
// Ex 5 Operacoes
#include <stdio.h>

void le_vetor(int l[], int n){
    int i;
    printf("Escreva um a um o valor da lista\n");
    for (i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
}

int max(int l[], int n){
    int i, k;
    for ( i=0; i<n; i++){
        if (i == 0)
            k = l[i];
        else if ( k < l[i])
            k = l[i];
    }
    return k;
}

int min(int l[], int n){
    int i, k;
    for ( i=0; i<n; i++){
        if (i == 0)
            k = l[i];
        else if ( k > l[i])
            k = l[i];
    }
    return k;
}

int mean(int l[], int n) {
    int i, s = 0;
    for (i = 0; i < n; i++) {
        s = s + l[i];
    }
    return s / n;
}


int l[10000], n, x;
int main(){
    int i;
    printf("Qual sera o tamanho da listas?\n");
    scanf("%d",&n);    
    le_vetor(l,n);
    x = max(l,n);
    printf("Maximo eh %d \n", x);
    x = min(l,n);
    printf("Minimo eh %d \n", x);
    x = mean(l,n);
    printf("Media eh %d \n", x);
}

