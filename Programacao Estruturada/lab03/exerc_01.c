#include <stdio.h>
#define MAX 1000

int main()
{
    int i;
    char frase[MAX], simb[1];
    printf("Ate qual char deseja ir?\n");
    scanf("%c",&simb);
    getchar();
    printf("Escreva sua frase:\n");
    scanf("%s",&frase);
    
    for (i=0; i<MAX; i++){
        if (frase[i] != simb[0]){
            printf("%c",frase[i]);
        }
        else{
            break;
        }
    }
    return 0;
}
