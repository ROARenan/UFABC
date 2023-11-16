#include <stdio.h>
#include <stdlib.h>
/*
Crie uma função que receba outra função como parâmetro.
Ex:
int square(int a) {
    return a * a;
}

void map(int array[], int n, int func(int)) {
    for (int i = 0; i < n; i++)
        array[i] = func(array[i]);
}

int main(int argc, char *argv[]) {
    int vet[5] = {1, 2, 3, 4, 5};
    map(vet, 5, square);
}
*/
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
            i++;
        }
        return 1;
    }
}

int main(){
    
    return 0;
}