#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int capacity; // capacidade do 'array' data
    int nelements; // número de elementos guardados em data
}* VectorInt;

VectorInt* vectorint(void){
    VectorInt* v = (VectorInt*) malloc(sizeof(VectorInt));
    (*v)->data = (int*) malloc(1*sizeof(int));
    (*v)->capacity = 1;
    (*v)->nelements = 0;
    return v;
}

void vectorint_insert(VectorInt* v, int a){
    if ((*v)->capacity > (*v)->nelements){
        (*v)->data[(*v)->nelements] = a;
        (*v)->nelements++;
    }
    else{
        (*v)->capacity = (*v)->capacity * 2;
        (*v)->data = realloc((*v)->data,(*v)->capacity * sizeof(int));
        (*v)->data[1] = a;
    }
}

void vectorint_remove(VectorInt* v, int a){
    int i;
    for (i=0;i<(*v)->nelements;i++){
        if ((*v)->data[i]==a){
            for (int j=i;j<(*v)->nelements-1;j++){
                (*v)->data[j] = (*v)->data[j+1];
            }
            (*v)->nelements--;
            break;
        }
    }

    if ((*v)->nelements < ((*v)->capacity/2)){
        (*v)->data = realloc((*v)->data, ((*v)->capacity/2) * sizeof(int));
    }
}

int vectorint_at(VectorInt* v, int i){
    return (*v)->data[i];
}

void vectorint_print_elements(VectorInt* v){
    for (int i=0;i<(*v)->nelements;i++){
        printf("%d ",(*v)->data[i]);
    }
    printf("\n");
}

void vectorint_status(VectorInt* v){
    printf("Status do vector:\n");
    printf("Capacidade: %d\n",(*v)->capacity);
    printf("Numero de Elementos: %d\n",(*v)->nelements);
}

void vectorint_free(VectorInt* v) {
    free((*v)->data);
    free(v);
}

int main() {
    VectorInt* v = vectorint();

    vectorint_insert(v, 10);
    vectorint_insert(v, 20);
    vectorint_insert(v, 30);
    vectorint_status(v);

    //vectorint_print_elements(v);
    vectorint_remove(v, 20);
    vectorint_print_elements(v);
    vectorint_free(v);

    return 0;
}