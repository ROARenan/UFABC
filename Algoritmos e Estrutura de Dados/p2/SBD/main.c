#include "database.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
    Database* database = db_create();
    User* users[] = {
        users[0] = user_create(123, "a@a.c", "name1", "password1"),
        users[1] = user_create(456, "m@z.x", "name2", "password2"),
        users[2] = user_create(789, "m@a.b", "name3", "password3"),
        users[3] = user_create(321, "b@c.d", "name4", "password4"),
        users[4] = user_create(654, "z@w.c", "name5", "password5"),
        users[5] = user_create(987, "a@a.a", "name6", "password6")
    };

    for (int i = 0; i < 6; i++) {
        db_insert(database, users[i]);
    }

    db_printInOrder(database);
    printf("\n");

    for (int i = 0; i < 6; i++) {
        User* user = db_query(database, users[i]->email);

        if (user != NULL) {
            printf("Found user: ");
            user_print(user);
        } else {
            printf("User not found\n");
        }
    }

    for (int i = 0; i < 6; i++) {
        db_remove(database, users[i]->email);
        db_printInOrder(database);
        printf("\n");
    }

    db_destroy(database);

    for (int i = 0; i < 6; i++) {
        user_destroy(users[i]);
    }

    return 0;
}