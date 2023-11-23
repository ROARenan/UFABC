//Renan Santana RA: 11202131332

#include <stdio.h>

int slen(char word[]){
    int cont = 0;
    while (word[cont] != '\0'){
        cont++;
    }
    // printf("%d\n",cont);
    return cont;
}

char inverte(char word[], int ini, int fim){
    char hold;
    if (ini >= fim){
        return 0;
    }
    hold = word[ini];
    word[ini] = word[fim];
    word[fim] = hold;
    return inverte(word,ini+1,fim-1);
}

int main(){
    char word[] = "luiz";
    int n = slen(word);
    inverte(word,0,n-1);
    printf("%s\n",word);
    return 0;
}
