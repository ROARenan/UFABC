#ifndef USER_H
#define USER_H

typedef struct User {
    unsigned int id;
    char email[256];
    char name[256];
    char password[256];
} User;

void user_print(User* element);
User* user_create(unsigned int id, const char* email, const char* name, const char* password);
void user_destroy(User* element);

#endif