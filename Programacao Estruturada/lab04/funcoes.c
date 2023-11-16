#include <stdio.h>
#include <stdlib.h>


//MONTA VETOR DINAMICO
void monta_vetor(int n, int ** v){
    int i;
    *v = malloc(n * sizeof(int));
    if (*v == NULL){
        printf("Nao ha memoria o suficiente");
        exit(1);
        }
    for (i=0;i<n;i++){
        scanf("%d",&(*v)[i]);
        printf("O valor da posicao eh %d\n",(*v)[i]);
    }
}

int n, *v;
int main(){
    int i;
    printf("Entre com os tamanho do \n");
    //printf("Entre com os dois arrays\n");
    scanf("%d", &n);
    monta_vetor(n, &v);
    //scanf("%d", &b);
    //printf("a = %d\n", a); // imprime: 'a: 7'
    for (i=0;i<n;i++){
        printf("%d, ",v[i]);
    }
    free(v);
    return 0;
}