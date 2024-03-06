#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdbool.h>

#include "student.h"

typedef struct SortedList SortedList;

SortedList* slist_create();
void slist_destroy(SortedList* list);
int slist_size(SortedList* list);
Student* slist_get(SortedList* list, int pos);
Student* slist_getMin(SortedList* list);
Student* slist_getMax(SortedList* list);
bool slist_is_empty(SortedList* list);
void slist_print(SortedList* list);

// new functions
bool slist_insert(SortedList *list, unsigned int ra, const char* name, float grade);

#endif