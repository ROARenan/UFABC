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
    	printf("%d ", atual ->valor);
	printf("\n");
}

int main(){
	Lista l = lista_cria();
	l = lista_add(l,1);
	l = lista_add(l,15);
	lista_print(l);
	destruir_lista(l);
	return 0;
}
