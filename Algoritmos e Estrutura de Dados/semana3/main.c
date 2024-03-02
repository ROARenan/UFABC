#include <stdio.h>

#include "student_list.h"

int main(void) {
    StudentList* list = list_create();

    list_insertFirst(list, 123, "John Doe", 7.5);
    list_insertFirst(list, 456, "Mary Jane", 5.5);
    list_insertFirst(list, 789, "Peter Parker", 6.5);
    list_insertFirst(list, 101, "Alice Cooper", 4.5);

    list_print(list);

    list_insertAfter(list, 2, 999, "Bruce Wayne", 8.5);

    list_print(list);

    list_destroy(list);

    return 0;
}
