#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int hold = *a;
    *a = *b;
    *b = hold;
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