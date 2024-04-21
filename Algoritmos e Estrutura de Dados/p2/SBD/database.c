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

// handlers
User *user_search(Node *root, char *email)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (strcmp(root->user->email, email) == 0)
    {
        return root->user;
    }

    if (strcmp(root->user->email, email) > 0)
    {
        return user_search(root->left, email);
    }
    else
    {
        return user_search(root->right, email);
    }
}

bool user_insert (Node *root, User *user)
{
    if (root == NULL)
    {
        return user_create(user->id,user->email, user->name, user->password);
    }

    if (strcmp(root->user->email, user->email) > 0){
        return user_insert(root->left, user);
    }
    if (strcmp(root->user->email, user->email) < 0){
        return user_insert(root->right, user);
    }
    
}

Node *user_minEmail(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node *user_remove(Node *root, const char *email) {
    // Caso base: se a árvore está vazia ou o nó a ser removido não existe
    if (root == NULL) {
        return NULL;
    }

    // Busca o nó a ser removido
    if (strcmp(email, root->user->email) < 0) {
        root->left = user_remove(root->left, email);
    } else if (strcmp(email, root->user->email) > 0) {
        root->right = user_remove(root->right, email);
    } else { // Nó a ser removido foi encontrado
        // Caso 1: nó não tem filhos
        if (root->left == NULL && root->right == NULL) {
            free(root->user);
            free(root);
            return NULL;
        }
        // Caso 2: nó tem apenas um filho à direita
        else if (root->left == NULL) {
            Node *temp = root->right;
            free(root->user);
            free(root);
            return temp;
        }
        // Caso 3: nó tem apenas um filho à esquerda
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root->user);
            free(root);
            return temp;
        }
        // Caso 4: nó tem dois filhos
        else {
            // Encontra o sucessor do nó atual (menor nó na subárvore direita)
            Node *temp = user_minEmail(root->right);
            // Copia os dados do sucessor para o nó atual
            root->user = temp->user;
            // Remove o sucessor da subárvore direita
            root->right = user_remove(root->right, temp->user->email);
        }
    }

    return root;
}

void user_print(User * user){
    printf("Ola amigos");
}

// new functions

User *db_query(Database *db, const char *email)
{
    return user_search(db->root, email);
}

void db_insert(Database *db, User *student)
{
}
void db_remove(Database *db, const char *email)
{
    nodeRemove(db->root, email);
}

// Função auxiliar para imprimir os dados de um nó
void printUserData(User *user) {
    printf("ID: %d, Email: %s, Name: %s, Password: %s\n", user->id, user->email, user->name, user->password);
}

// Função auxiliar para imprimir a árvore binária de busca em pré-ordem
void printPreOrder(Node *root) {
    if (root != NULL) {
        printUserData(root->user); // Imprime o nó atual
        printPreOrder(root->left); // Recursivamente imprime a subárvore esquerda
        printPreOrder(root->right); // Recursivamente imprime a subárvore direita
    }
}

// Função auxiliar para imprimir a árvore binária de busca em ordem
void printInOrder(Node *root) {
    if (root != NULL) {
        printInOrder(root->left); // Recursivamente imprime a subárvore esquerda
        printUserData(root->user); // Imprime o nó atual
        printInOrder(root->right); // Recursivamente imprime a subárvore direita
    }
}

// Função auxiliar para imprimir a árvore binária de busca em pós-ordem
void printPostOrder(Node *root) {
    if (root != NULL) {
        printPostOrder(root->left); // Recursivamente imprime a subárvore esquerda
        printPostOrder(root->right); // Recursivamente imprime a subárvore direita
        printUserData(root->user); // Imprime o nó atual
    }
}

// Função principal para imprimir a árvore binária de busca em pré-ordem
void db_printPreOrder(Database *db) {
    printf("Printing PreOrder:\n");
    printPreOrder(db->root);
    printf("\n");
}

// Função principal para imprimir a árvore binária de busca em ordem
void db_printInOrder(Database *db) {
    printf("Printing InOrder:\n");
    printInOrder(db->root);
    printf("\n");
}

// Função principal para imprimir a árvore binária de busca em pós-ordem
void db_printPostOrder(Database *db) {
    printf("Printing PostOrder:\n");
    printPostOrder(db->root);
    printf("\n");
}