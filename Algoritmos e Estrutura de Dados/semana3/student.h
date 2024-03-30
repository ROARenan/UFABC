#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    unsigned int ra;
    char name[50];
    float grade;
} Student;

Student* student_create(unsigned int id, char name[50], float grade);
void student_destroy(Student* s);
int student_compare(Student* s1, Student* s2);
void student_print(Student* s);

#endif