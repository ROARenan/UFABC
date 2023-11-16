#include <stdio.h>
#include <stdlib.h>

int n,i;
int main(){
    scanf("%d",&n);
    int *v = malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    for (i=0;i<n;i++){
        printf("entrada %d, conteudo %d, endereco: %lld\n",i,v[i],&v[i]);
    }
    free(v);
    return 0;
}