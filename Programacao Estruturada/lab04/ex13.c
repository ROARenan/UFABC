#include <stdio.h>
#include <stdlib.h>

typedef struct _aluno{
    int ra;
    char nome[1000];
    char sexo;
    int idade;
}* Aluno;

char aluno_cmp(Aluno *a, Aluno *b){
    int i = 0, r = 1;
    if ((*a)->ra == (*b)->ra && (*a)->idade == (*b)->idade &&  (*a)->sexo == (*b)->sexo){
        while ((*a)->nome[i] != '\0' && (*b)->nome[i] != '\0'){
            if ((*a)->nome[i] != (*b)->nome[i]){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    
    return 0;
}