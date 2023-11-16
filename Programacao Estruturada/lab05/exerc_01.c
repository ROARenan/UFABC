#include <stdio.h>
#include <stdlib.h>

void count_down(int n){
    if (n!=0){
        printf("%d\n",n);
        return count_down(n-1);
    }
    printf("ACABOU!\n");

}

int main(){
    count_down(5);
    return 0;
}
