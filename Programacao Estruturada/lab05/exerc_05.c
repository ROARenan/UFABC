#include <stdio.h>
#include <math.h>

int hanoi(int n){
    int r;
    printf("hanoi de %d\n",n);
    if (n>=0){
        if (n==1){
            printf("r vale 2\n");
            return 2;
        }
        else{
            r = 2*hanoi(n-1);
            printf("r vale %d\n",r);
            return r-1;
        }
    }
}

int main(){
    int n;
    printf("Qual o numero de discos da torre?\n");
    scanf("%d",&n);
    printf("%d\n",hanoi(n));
    return 0;
}