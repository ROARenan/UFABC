#include <stdio.h>
#include <math.h>

int collatz(int n){
    printf("%d ",n);
    if (n != 1){
        if (n%2 == 0){
            n = n/2;
            collatz(n);
        }
        else{
            n = n*3 + 1;
            collatz(n);
        }
    }
    
}

int main(){
    int n;
    printf("Qual o numero de de inicio do Collatz?\n");
    scanf("%d",&n);
    collatz(n);
    return 0;
}