#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nAlunos;
    double notas;
    double highNota;

} Avaliacao;

Avaliacao * cria_lista_avaliacao(int n){
    Avaliacao *v = malloc(n * sizeof(Avaliacao));
    int i;
    double x;
    printf("Entre com as notas uma a uma\n");
    for (i=0;i<n;i++){
        scanf("%d",&x);
        v[i].notas = x;
    }
    return v;
}

int main(){
    int n, i;
    printf("Quantos alunos fizeram a prova?\n");
    scanf("%d", &n);
    return 0;
}