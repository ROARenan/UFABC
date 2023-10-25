#include <stdio.h>
#define MAX 1000

typedef struct
{
    int vetor[MAX];
}Conjunto;

Conjunto conjunto(int vet[]) {
    Conjunto a;
    int i;
    for (i = 0; i < sizeof(vet); i++) {
        a.vetor[i] = vet[i];
    }
}

void conjunto_write(Conjunto a) {
    int i;
    for (i = 0; i < sizeof(a.vetor); i++){
        printf("%d,\n",a.vetor[i]);
    }
}

Conjunto conjunto_uniao(Conjunto a, Conjunto b) {
    Conjunto c;
    c = a;
    int i, j, r = 1;
    for (i = 0; i < sizeof(b.vetor); i++) {
        for (j = 0; j < sizeof(c.vetor); j++) {
            if (b.vetor[i] == c.vetor[j]){
                r = 0;
                break;
            }
        }
        if (r = 1)
            c.vetor[sizeof(c.vetor)+1] = b.vetor[i];
    }

    return c;
} 

char conjunto_pertence(int n, Conjunto a){
    int i;
    for (i = 0; i < sizeof(a.vetor); i++){
        if (n == a.vetor[i]){
            return 1;
        }
    }
    return 0;
}

int main() {
    
    return 0;
}