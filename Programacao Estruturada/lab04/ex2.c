#include <stdio.h>
#include <stdlib.h>

int n,i;
int main(){
    scanf("%d",&n);
    char *v = malloc(n*sizeof(char));

    for(i=0;i<n;i++){
        getchar();
        scanf("%c",&v[i]);
        //printf("%c",v[i]);
        
    }
    for (i=0;i<n;i++){
        printf("entrada %d, conteudo %c, endereco: %lld\n",i,v[i],&v[i]);
    }
    free(v);
    return 0;
}