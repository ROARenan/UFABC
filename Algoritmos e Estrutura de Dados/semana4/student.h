#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    unsigned int ra;
    char name[50];
    float grade;
} Student;


Student* student_create(unsigned int ra, const char* name, float grade);
void student_destroy(Student* s);
void student_print(Student* s);

#endif