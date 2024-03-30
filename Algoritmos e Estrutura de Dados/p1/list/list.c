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
    printf("Ascending:\n");
    while (cur != NULL)
    {
        printf("%d <= %d\n", cur->value, last);
        if (cur->value <= last)
        {
            is_desc = 1;
        }
        else
        {
            is_desc = 0;
        }
        if (is_desc == 0)
        {
            break;
        }
        last = cur->value;
        cur = cur->next;
    }

    cur = l->head;
    last = cur->value;
    printf("Descending:\n");
    while (cur != NULL)
    {
        printf("%d >= %d\n", cur->value, last);
        if (cur->value >= last)
        {
            is_asc = 1;
        }
        else
        {
            is_asc = 0;
        }
        if (is_asc == 0)
        {
            break;
        }
        last = cur->value;
        cur = cur->next;
    }

    if (is_asc == 1 && is_desc == 1)
    {
        return 0;
    }
    if (is_asc == 1 && is_desc == 0)
    {
        return 1;
    }
    if (is_asc == 0 && is_desc == 1)
    {
        return 2;
    }

    return 0;
}

void list_removeDuplicates(List *l)
{
    Node *cur1 = l->head;
    Node *cur2;
    Node *hold;
    Node *last2;

    while (cur1 != NULL)
    {
        last2 = cur1;
        cur2 = cur1->next;
        while (cur2 != NULL)
        {
            if (cur1->value == cur2->value)
            {
                hold = cur2;
                last2->next = cur2->next;
                cur2 = cur2->next;
                free(hold);
            }
            else
            {
                last2 = cur2;
                cur2 = cur2->next;
            }
        }

        cur1 = cur1->next;
    }
}

void list_printReverse(List* l) {
    Node* cur = l->head;
    Node* last = NULL;
    
    while (cur->next != NULL) {
        last = cur;
        cur = cur->next;
    }

    while (last != NULL) {
        element_print(cur->value);
        printf(">> ");
        if (last != l->head) {
            cur = last;
            last = l->head;
            while (last->next != cur) {
                last = last->next;
            }
        } else {
            break;
        }
    }
}
