#include <stdio.h>
#include <stdlib.h>

typedef struct {
int* data;
int capacity; // capacidade do 'array' data
int nelements; // número de elementos guardados em data
}* VectorInt;

VectorInt* vectorint(void){
    VectorInt v;
    VectorInt *p = &v;
    v->data = malloc(1*sizeof(VectorInt));
    v->capacity = 1;
    v->nelements = 0;
    return p;
}

void vectorint_insert(VectorInt v, int a){
    int x;
    if (v->capacity > v->nelements){
        v->data[v->nelements] = scanf("%d",&x);
        v->nelements++;
    }
    else{
        v->capacity = v->capacity * 2;
        v->data = realloc(v->data,v->capacity * sizeof(int));
        v->data[v->nelements] = scanf("%d",&x);
    }

}

void vectorint_remove(VectorInt v, int a){
    int i = 0;
    for (i=0;i<v->capacity;i++){
        if (v->data[i]==a){
            v->data[i] = NULL;
        }
    }
}

int vectorint_at(VectorInt v, int i){
    return v->data[i];
}

void vectorint_print_elements(VectorInt v, int i){
    int i = 0;
    for (i=0;i<v->capacity;i++){
        printf("%d",v->data[i]);
    }
}

void vectorint_status(VectorInt v){
    printf("Status do vertor:\n");
    printf("Capacidade: %d\n",v->capacity);
    printf("Numero de Elementos: %d\n",v->nelements);
}

void vectorint_free(VectorInt v) {
    free(v->data);
    free(v);
}

int n;
int main() {
    VectorInt *v = vectorint();
    return 0;
}