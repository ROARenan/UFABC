#include <stdio.h>
#include <stdlib.h>

void swap(int *ax,int *bx){
    int hold = *ax;
    *ax = *bx;
    *bx = hold;
}

int a, b;
int main(){
    printf("Entre com os numeros\n");
    scanf("%d", &a);
    scanf("%d", &b);
    swap(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}