//Renan Santana RA: 11202131332

#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int n){
    if (n!=0){
        return v[n-1] + soma(v, n-1);
    }
    return 0;
}

int main(){
    int v[] = {1,2,3,4,5};
    printf("%d\n", soma(v,5));
    return 0;
}
