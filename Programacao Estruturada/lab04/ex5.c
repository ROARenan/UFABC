#include <stdio.h>
#include <stdlib.h>

void inc(int *x){
    (*x)++;
}

int x;
int main(){
    printf("Entre com o numero a incrementar\n");
    scanf("%d", &x);
    inc(&x);
    printf("x = %d\n", x);

    return 0;
}