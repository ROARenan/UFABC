#include "bst_algs.h"

#include <stdlib.h>
#include <stdio.h>

Node* bst_createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void bst_destroy(Node *root) {
    if (root == NULL) {
        return;
    }
    bst_destroy(root->left);
    bst_destroy(root->right);
    free(root);
}

Node* bst_insert(Node* node, int key) {
    if (node == NULL) {
        return bst_createNode(key);
    }
    if (key < node->key) {
        node->left = bst_insert(node->left, key);
    } else if (key > node->key) {
        node->right = bst_insert(node->right, key);
    }

    return node;
}

int main() {
    int seq1[] = {10, 5, 15, 3, 7, 12, 18};
    int seq2[] = {11, 2, 3, 1, 8, 5, 19};

    Node* tree1 = bst_createNode(seq1[0]);
    Node* tree2 = bst_createNode(seq2[0]);

    for (int i = 1; i < 7; i++) {
        tree1 = bst_insert(tree1, seq1[i]);
        tree2 = bst_insert(tree2, seq2[i]);
    }

    printf("Tree 1 has %d nodes\n", bst_countNodes(tree1));
    printf("Tree 2 has %d nodes\n", bst_countNodes(tree2));

    printf("Tree 1 has %d leaves\n", bst_countLeaves(tree1));
    printf("Tree 2 has %d leaves\n", bst_countLeaves(tree2));

    printf("Tree 1 has %d internal nodes\n", bst_countInternalNodes(tree1));
    printf("Tree 2 has %d internal nodes\n", bst_countInternalNodes(tree2));

    printf("Tree 1 has height %d\n", bst_height(tree1));
    printf("Tree 2 has height %d\n", bst_height(tree2));

    printf("Tree 1 has sum %d\n", bst_sum(tree1));
    printf("Tree 2 has sum %d\n", bst_sum(tree2));

    printf("Tree 1 has max %d\n", bst_max(tree1));
    printf("Tree 2 has max %d\n", bst_max(tree2));

    printf("Trees 1 and 2 have %d shared keys\n", bst_countSharedKeys(tree1, tree2));
    printf("Trees 2 and 1 have %d shared keys\n", bst_countSharedKeys(tree2, tree1));

    bst_destroy(tree1);
    bst_destroy(tree2);

    return 0;
}