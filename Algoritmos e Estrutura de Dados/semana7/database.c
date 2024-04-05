#include "database.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    User *user;
    struct Node *left;
    struct Node *right;
} Node;

struct Database
{
    Node *root;
};

Database *db_create()
{
    Database *bst = malloc(sizeof(Database));

    bst->root = NULL;

    return bst;
}

void bst_destroyRecur(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->left != NULL)
    {
        bst_destroyRecur(node->left);
    }
    if (node->right != NULL)
    {
        bst_destroyRecur(node->right);
    }
    free(node);
}

void db_destroy(Database *bst)
{
    bst_destroyRecur(bst->root);
    free(bst);
}

int db_sizeRecur(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + db_sizeRecur(node->left) + db_sizeRecur(node->right);
}

int db_size(Database *db)
{
    return db_sizeRecur(db->root);
}

// Func do prof adaptada
Node *searchEmailRecur(Node *cur, const char *email)
{
    if (cur == NULL)
    {
        return NULL;
    }

    int comp = strcmp(cur->user->email, email);
    if (comp == 0)
    {
        return cur;
    }
    else if (comp < 0)
    {
        return searchEmailRecur(cur->right, email);
    }
    else
    {
        return searchEmailRecur(cur->left, email);
    }
}

Node *getMinEmailNode(Node *cur)
{
    if (cur == NULL)
    {
        return NULL;
    }

    if (cur->left == NULL)
    {
        return cur;
    }

    return getMinEmailNode(cur->left);
}

Node *nodeCreate(User *user)
{
    Node *nNode = malloc(sizeof(Node));
    nNode->user = user;
    nNode->left = NULL;
    nNode->right = NULL;
    return nNode;
}

Node *nodeInsert(Node *cur, User *user)
{
    if (cur == NULL)
    {
        return nodeCreate(user);
    }

    int comp = strcmp(cur->user->email, user->email);
    if (comp > 0)
    {
        cur->left = nodeInsert(cur->left, user);
    }
    else if (comp < 0)
    {
        cur->right = nodeInsert(cur->right, user);
    }
    return cur;
}

Node *nodeRemove(Node *cur, const char *email)
{
    if (cur == NULL){
        return NULL;
    }
    int comp = strcmp(cur->user->email, email);

    if (comp > 0)
        cur->left = nodeRemove(cur->left, email);
    else if (comp < 0)
        cur->right = nodeRemove(cur->right, email);
    else
    {
        if (cur->left == NULL)
        {
            Node *temp = cur->right;
            free(cur);
            return temp;
        }
        else if (cur->right == NULL)
        {
            Node *temp = cur->left;
            free(cur);
            return temp;
        }
        else
        {
            Node *temp = getMinEmailNode(cur->right);
            cur->user = temp->user;
            cur->right = nodeRemove(cur->right, temp->user->email);
            if (cur->right == temp)
                cur->right = temp->right;
        }
    }
    return cur;
}

// new functions
User *db_query(Database *db, const char *email)
{
    Node *nodeFind = searchEmailRecur(db->root, email);
    if (nodeFind != NULL)
    {
        return nodeFind->user;
    }
    else
    {
        return NULL;
    }
}

void db_insert(Database *db, User *student)
{
    if (db->root == NULL)
    {
        db->root = nodeCreate(student);
    }
    else
    {
        if (searchEmailRecur(db->root, student->email) == NULL)
        {
            db->root = nodeInsert(db->root, student);
        }
    }
}

void db_remove(Database *db, const char *email)
{
    nodeRemove(db->root, email);
}

void auxPreOrder(Node *cur)
{
    if (cur != NULL)
    {
        user_print(cur->user);
        auxPreOrder(cur->left);
        auxPreOrder(cur->right);
    }
}

void db_printPreOrder(Database *db)
{
    if (db->root == NULL)
    {
        printf("Empty database");
    }
    else
    {
        printf("Id, Email, Name, Password\n");
        auxPreOrder(db->root);
    }
}

void auxInOrder(Node *cur)
{
    if (cur != NULL)
    {
        auxInOrder(cur->left);
        user_print(cur->user);
    }

    if (cur != NULL && cur->right == NULL && cur->left != NULL)
    {
        user_print(cur->left->user);
    }
}

void db_printInOrder(Database *db)
{
    if (db->root == NULL)
    {
        printf("Empty database");
    }
    else
    {
        printf("Id, Email, Name, Password\n");
        auxInOrder(db->root);
    }
}

void auxPostOrder(Node *cur)
{
    if (cur != NULL)
    {
        auxPostOrder(cur->left);
        auxPostOrder(cur->right);
        user_print(cur->user);
    }
}
void db_printPostOrder(Database *db)
{
    if (db->root == NULL)
    {
        printf("Empty database");
    }
    else
    {
        printf("Id, Email, Name, Password\n");
        auxPostOrder(db->root);
    }
}
int db_size(Database *db);