#ifndef LIST_H
#define LIST_H

#include "element.h"
#include <stdbool.h>

typedef struct List List;

List *create_list();
void print_list(List *l);
void destroy_list(List *l);
void insertEnd_list(List *l, Element x);
void list_printElements(List* l1, List* l2);
bool list_equals(List* l1, List* l2);
int list_isSorted(List* l);
void list_removeDuplicates(List *l);

#endif