#include <stdio.h>
#include <stdlib.h>

void combinacoes(int v[], int n, int k, int i){
    if (n<k){
        printf("Nao eh possivel combinar");
        return;
    }
    
}

int main()
{
    int n, j, k;
    printf("Digite o n:\n");
    scanf("%d", &n);
    printf("Digite o k:\n");
    scanf("%d", &k);
    int *v = malloc(n*sizeof(int));

    printf("Os valores de a combinar:\n");
    for (j=0;j<n;j++){
        scanf("%d", &v[j]);
    }

    combinacoes(v,n,k,0);
    /*printf("Os valores de av sao:\n");
    for (j=0;j<n;j++){
        printf("%d\n",v[j]);
    }*/
    return 0;
}