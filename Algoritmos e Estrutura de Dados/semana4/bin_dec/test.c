#include <stdio.h>

int divs_by_two(int n) {
    int cont = 0;
    
    while (n > 1) {
        n = n / 2;
        cont++;
    }
    
    return cont+1;
}

int main()
{
    printf("%d\n", divs_by_two(45));
    return 0;
}