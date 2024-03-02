#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "student.h"

typedef struct StudentList StudentList;

StudentList *list_create();
void list_destroy(StudentList *list);
Student* list_get(StudentList *list, int position);
void list_print(StudentList *list);
void list_insertFirst(StudentList *list, unsigned int ra, char* name, float grade);
void list_insertAfter(StudentList *list, int position, unsigned int ra, char* name, float grade);
int list_size(StudentList *list);
bool list_isEmpty(StudentList *list);

// new functions
Student* list_findByRa(StudentList* list, unsigned int ra);
void list_incrementGrades(StudentList* list, float amount);
float list_averageGrade(StudentList* list);
StudentList* list_filterFailed(StudentList* list);
StudentList* list_filterPassed(StudentList* list);
StudentList* list_filterExam(StudentList* list);


#endif