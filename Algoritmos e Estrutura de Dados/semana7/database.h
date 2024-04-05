#ifndef DATABASE_H
#define DATABASE_H

#include <stdbool.h>

#include "user.h"

typedef struct Database Database;

Database* db_create();
void db_destroy(Database* db);
User* db_query(Database* db, const char* email);
void db_insert(Database* db, User* student);
void db_remove(Database* db, const char* email);
void db_printPreOrder(Database* db);
void db_printInOrder(Database* db);
void db_printPostOrder(Database* db);
int db_size(Database* db);

#endif