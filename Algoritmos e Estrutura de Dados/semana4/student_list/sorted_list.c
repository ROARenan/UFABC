#include "sorted_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    Student *student;
    struct Node *next;
} Node;

struct SortedList
{
    Node *first;
    Node *last;
    int size;
};

SortedList *slist_create()
{
    SortedList *list = (SortedList *)malloc(sizeof(SortedList));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void slist_destroy(SortedList *list)
{
    while (list->first != NULL)
    {
        Node *trash = list->first;

        list->first = list->first->next;
        student_destroy(trash->student);
        free(trash);
    }
    free(list);
}

int slist_size(SortedList *list)
{
    return list->size;
}

Student *slist_get(SortedList *list, int pos)
{
    if (pos < 0 || pos >= list->size)
    {
        return NULL;
    }

    Node *cur = list->first;

    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }

    return cur->student;
}

Student *slist_getMin(SortedList *list)
{
    if (list->first == NULL)
    {
        return NULL;
    }
    return list->first->student;
}

Student *slist_getMax(SortedList *list)
{
    if (list->last == NULL)
    {
        return NULL;
    }

    return list->last->student;
}

bool slist_is_empty(SortedList *list)
{
    return list->first == NULL;
}

void slist_print(SortedList *list)
{
    Node *cur = list->first;

    while (cur != NULL)
    {
        student_print(cur->student);
        if (cur->next != NULL)
        {
            printf(" -> ");
        }
        cur = cur->next;
    }
    printf("\n");
}

// new functions

bool slist_insert(SortedList *list, unsigned int ra, const char *name, float grade)
{
    Node *cur = list->first;
    Node *bef = NULL;
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }

    new_node->student = student_create(ra, name, grade);
    new_node->next = NULL;

    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
        list->size++;
        return true;
    }

    if (ra < list->first->student->ra) {
        new_node->next = list->first;
        list->first = new_node;
        list->size++;
        return true;
    }

    while (cur != NULL && ra > cur->student->ra) {
        bef = cur;
        cur = cur->next;
    }

    if (cur != NULL && ra == cur->student->ra) {
        student_destroy(new_node->student);
        free(new_node);
        return false;
    }

    if (cur == NULL) {
        list->last->next = new_node;
        list->last = new_node;
        list->size++;
        return true;
    }

    bef->next = new_node;
    new_node->next = cur;
    list->size++;
    return true;
}

