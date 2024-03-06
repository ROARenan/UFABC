/**
 * NAO EDITE AS FUNCOES QUE JA ESTAO PRONTAS,
 * APENAS IMPLEMENTE AS NOVAS
 */

#include "student_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    Student *student;
    struct Node *next;
} Node;

struct StudentList
{
    Node *head;
};

StudentList *list_create()
{
    StudentList *list = malloc(sizeof(StudentList));

    list->head = NULL;

    return list;
}

void list_destroy(StudentList *list)
{
    Node *trash = list->head;

    while (trash != NULL)
    {
        list->head = trash->next;

        student_destroy(trash->student);
        free(trash);
        trash = list->head;
    }
    free(list);
}

void list_insertFirst(StudentList *list, unsigned int ra, char *name, float grade)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->student = student_create(ra, name, grade);
    newNode->next = list->head;
    list->head = newNode;
}

void list_insertAfter(StudentList *list, int position, unsigned int ra, char *name, float grade)
{
    if (position <= 0 || list->head == NULL)
    {
        list_insertFirst(list, ra, name, grade);
    }
    else
    {
        Node *cur = list->head;
        int i = 0;

        while (i < position && cur->next != NULL)
        {
            cur = cur->next;
            i++;
        }

        Node *newNode = malloc(sizeof(Node));

        newNode->student = student_create(ra, name, grade);
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

Student *list_get(StudentList *list, int position)
{
    if (position < 0)
    {
        return list->head->student;
    }

    Node *cur = list->head;
    int i = 0;

    while (i < position && cur->next != NULL)
    {
        cur = cur->next;
        i++;
    }

    return cur->student;
}

void list_print(StudentList *list)
{
    Node *cur = list->head;

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

int list_size(StudentList *list)
{
    Node *cur = list->head;
    int count = 0;

    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

bool list_isEmpty(StudentList *list)
{
    return list->head == NULL;
}

// new functions

Student *list_findByRa(StudentList *list, unsigned int ra)
{
    Node *cur = list->head;
    int i = 0;

    while (cur->next != NULL)
    {
        if (cur->student->ra == ra)
        {
            return cur->student;
        }
        cur = cur->next;
        i++;
    }
    if (cur->student->ra == ra)
    {
        return cur->student;
    }

    return NULL;
}

void list_incrementGrades(StudentList *list, float amount)
{
    Node *cur = list->head;
    int i = 0;

    while (cur->next != NULL)
    {
        cur->student->grade = amount + cur->student->grade;
        cur = cur->next;
        i++;
    }
    cur->student->grade = amount + cur->student->grade;
}

float list_averageGrade(StudentList *list)
{
    Node *cur = list->head;
    int i = 0;
    float mean = 0;

    while (cur->next != NULL)
    {
        mean = mean + cur->student->grade;
        cur = cur->next;
        i++;
    }
    //mean = mean + cur->student->grade;
    return mean / (i + 1);
}

StudentList *list_filterFailed(StudentList *list)
{
    StudentList *hold = list_create();
    Node *cur = list->head;
    int i = 0;

    while (cur->next != NULL)
    {
        if (cur->student->grade < 6.0)
        {
            list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
        i++;
    }
    if (cur->student->grade < 6.0)
    {
        list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
    }
    return hold;
}

StudentList *list_filterPassed(StudentList *list)
{
    StudentList *hold = list_create();
    Node *cur = list->head;
    int i = 0;

    while (cur->next != NULL)
    {
        if (cur->student->grade >= 6.0)
        {
            list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
        i++;
    }
    if (cur->student->grade >= 6.0)
    {
        list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
    }
    return hold;
}

StudentList *list_filterExam(StudentList *list)
{
    StudentList *hold = list_create();
    Node *cur = list->head;
    int i = 0;

    while (cur->next != NULL)
    {
        if (cur->student->grade < 6.0 && cur->student->grade >= 4.0)
        {
            list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
        i++;
    }
    if (cur->student->grade < 6.0 && cur->student->grade >= 4.0)
    {
        list_insertFirst(hold, cur->student->ra, cur->student->name, cur->student->grade);
    }
    return hold;
}