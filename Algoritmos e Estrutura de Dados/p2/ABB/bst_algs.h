#ifndef REC_TREE_H
#define REC_TREE_H

#include <stdbool.h>
#include <limits.h>

#define MINIMUM INT_MIN
#define MAXIMUM INT_MAX

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

int bst_countNodes(Node *root);
int bst_countLeaves(Node *root);
int bst_countInternalNodes(Node *root);
int bst_height(Node *root);
int bst_sum(Node *root);
int bst_max(Node *root);
int bst_min(Node *root);
int bst_countSharedKeys(Node *root1, Node *root2);




#endif