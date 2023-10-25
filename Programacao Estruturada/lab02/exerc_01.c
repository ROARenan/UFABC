// Renan Santana Ferreira 11202131332
// Ex 1 Busca Valor

#include <stdio.h>

int busca_key(int l[], int n, int key){
    int indice;
    for (indice = 1; indice < n; indice++){
        if (key == l[indice]){
            return indice;
        }
    }
}

void mont_list(int l[], int n){
    int i;
    printf("Escreva um a um o valor da lista\n");
    for (i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
}


int n, l[10000000], key, x;

int main() {
    printf("Entre com o tamanho da lista \n");
    scanf("%d", &n);
    mont_list(l,n);
    printf("Qual valor deseja procurar? \n");
    scanf("%d", &key);
    x = busca_key(l,n,key);
    printf("%d", x);
    return 0;
}
