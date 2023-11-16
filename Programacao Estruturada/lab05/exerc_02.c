#include <stdio.h>
#include <stdlib.h>

void count_up(unsigned int n){
    if ( n == 0){
        printf("%d\n",0);
        return;
    }
    count_up(n-1);

    printf("%d\n",n);
}

int main(){
    count_up(5);
    return 0;
}
