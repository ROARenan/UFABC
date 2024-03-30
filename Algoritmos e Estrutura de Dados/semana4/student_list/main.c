#include <stdio.h>

#include "sorted_list.h"

int main(void) {
    SortedList *l = slist_create();
    printf("Lista Criada\n");

    slist_insert(l, 331, "Renan Santana", 5.6);
    slist_insert(l, 465, "Pessoa 2", 8.9);
    slist_print(l);

    slist_insert(l, 379, "Pessoa no meio", 6.9);
    slist_print(l);

    return 0;
}
