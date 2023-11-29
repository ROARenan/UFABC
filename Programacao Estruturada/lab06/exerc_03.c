#include <stdio.h>
#include <stdlib.h>

typedef struct no* Lista;

struct no{
	int valor;
	Lista next;
};

Lista lista_cria(){
	return NULL;
}

Lista lista_add(Lista l, int x) {
	Lista novo;
	novo = malloc(sizeof(struct no));
	novo ->valor = x;
	novo ->next = l;
	return novo;
}

void destruir_lista(Lista l){
	Lista hold;
	while (l != NULL){
    	hold = l;
    	l = l->next;
    	free(hold);
	}
}

void lista_print(Lista l) {
	Lista atual;
	for (atual = l; atual != NULL; atual = atual ->next)
    	printf("%d %p\n", atual ->valor, atual->next);
	printf("\n");
}

void lista_drop(Lista l, int x) {
    Lista r, ant = NULL;
    while (l != NULL) {
        if (l->valor == x) {
            r = l;
            if (ant != NULL) {
                ant->next = l->next;
            }
            free(l);
            break;
        }
        ant = l;
        l = l->next;
    }
    printf("Item removido com sucesso\n");
}

int main(){
	Lista l = lista_cria();
	l = lista_add(l,1);
	l = lista_add(l,15);
	l = lista_add(l,65);
	l = lista_add(l,40);
	l = lista_add(l,92);
	lista_print(l);
    printf("Apagando...\n");
    lista_drop(l, 65);
    lista_print(l);
	destruir_lista(l);
	return 0;
}
