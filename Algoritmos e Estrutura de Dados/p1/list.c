#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "element.h"

typedef struct Node
{
    Element value;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    int size;
} List;

List *create_list()
{
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    return l;
}

void print_list(List *l)
{
    struct Node *cur = l->head;
    while (cur != NULL)
    {
        element_print(cur->value);
        printf(">>");
        cur = cur->next;
    }
}

void insertEnd_list(List *l, Element x)
{
    Node *cur = l->head;
    Node *new_node = malloc(sizeof(Node));
    new_node->value = x;
    new_node->next = NULL;

    if (cur == NULL)
    {
        l->head = new_node;
    }
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    l->size++;
}

void destroy_list(List *l)
{
    Node *cur = l->head;
    Node *hold;

    while (cur != NULL)
    {
        hold = cur;
        cur = cur->next;
        free(hold);
    }
    free(l);
}

void list_printElements(List *l1, List *l2)
{
    Node *cur1 = l1->head;
    Node *cur2 = l2->head;
    int cont = 0;

    while (cur2 != NULL)
    {
        cont = 0;
        // printf("%d ", cur2->value);
        while (cur1 != NULL)
        {
            // printf("%d\n", cur1->value);
            if (cont == cur2->value)
            {
                printf("%d", cur1->value);
                printf(">> ");
                break;
            }
            cur1 = cur1->next;
            cont++;
        }
        cur1 = l1->head;
        cur2 = cur2->next;
    }
}

bool list_equals(List *l1, List *l2)
{
    Node *cur1 = l1->head;
    Node *cur2 = l2->head;
    if (l1->size != l2->size)
    {
        return false;
    }

    while (cur1 != NULL)
    {
        if (cur1->value != cur2->value)
        {
            return false;
        }
    }

    return true;
}

int list_isSorted(List *l)
{
    Node *cur = l->head;
    int last = cur->value;
    int is_asc = 0;
    int is_desc = 0;
    while (cur != NULL)
    {
        if (last < cur->value)
        {
            is_asc = 1;
        }
        else{
            is_asc = 0;
        }
        if (last > cur->value)
        {
            is_desc = 1;
        }
        else{
            is_desc = 0;
        }

        if (is_asc == 1 && is_desc == 1)
        {
            return 0;
        }

        cur = cur->next;
    }

    if (is_asc == 1){
        return 1;
    }
    else if (is_desc == 1){
        return 2;
    }

    else{
        return 0;
    }
}