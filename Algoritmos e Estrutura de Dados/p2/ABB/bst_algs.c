#include "bst_algs.h"

#include <stdio.h>
#include <stdbool.h>

int bst_searchKey(Node * root, int key){
  if (root == NULL){
    return 0;
  }

  if (root->key == key){
    return 1;
  }

  else if (key > root->key){
    return bst_searchKey(root->right, key);
  }
  else if (key < root->key){
    return bst_searchKey(root->left, key);
  }

  return 0;
}

int bst_countNodes(Node *root){
  if (root == NULL){
    return 0;
  }

  return 1 + bst_countNodes(root->left) + bst_countNodes(root->left);
}

int bst_countLeaves(Node *root){
  if (root == NULL){
    return 0;
  }

  if (root->left == NULL && root->right == NULL){
    return 1;
  }

  return bst_countLeaves(root->left) + bst_countLeaves(root->right);
}

int bst_countInternalNodes(Node *root){
  if (root == NULL){
    return 0;
  }

  if (root->left != NULL || root->right != NULL){
    return 1;
  }

  return bst_countInternalNodes(root->left) + bst_countInternalNodes(root->right);
}

int bst_height(Node *root){
  if (root == NULL){
    return 0;
  }
  
  int l_height = bst_height(root->left);
  int r_height = bst_height(root->right);
  if (l_height > r_height){
    return l_height + 1;
  }
  else {
    return r_height + 1;
  }
}

int bst_sum(Node *root){
  if (root == NULL){
    return 0;
  }

  return root->key + bst_sum(root->right) + bst_sum(root->left);
}

int bst_max(Node *root){
  if(root == NULL){
    return MINIMUM;
  }
  if (root->right == NULL){
    return root->key;
  }

  return(bst_max(root->right));
}

int bst_min(Node *root){
  if (root == NULL){
    return MAXIMUM;
  }

  if (root->left == NULL){
    return root->key;
  }
  
  return bst_min(root->left);
}

int bst_countSharedKeys(Node *root1, Node *root2){
  if (root1 == NULL || root2 == NULL){
    return MINIMUM;
  }
  int count = bst_countSharedKeys(root1->left, root2) + bst_countSharedKeys(root1->right, root2);

  if (bst_searchKey(root2, root1->key)){
    count++;
  }

  return count;
}

int bst_countSharedKeys(Node *root1, Node *root2){
  if (root1 == NULL || root2 == NULL){
    return 0;
  }

  return bst_searchKey(root2, root1->left->key) + bst_searchKey(root2, root1->right->key);
}