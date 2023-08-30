#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary node definition
typedef struct tree_node {
  // Info
  int key;
  int value;
  // Sons
  struct tree_node *left;
  struct tree_node *right;
  // Parent
  struct tree_node *parent;
} TreeNode;

// Tree definition
typedef struct tree {
  TreeNode *root;
} Tree;

// Create a new node
TreeNode * tree_node_create (int nkey, int nvalue) {
  TreeNode * ptr_new;
  ptr_new = (TreeNode *) malloc (sizeof(TreeNode));
  if (ptr_new == NULL) {
    printf ("Out of memory");
    exit (1);
  }
  //Info
  ptr_new->key = nkey;
  ptr_new->value = nvalue;
  //Sons
  ptr_new->left = NULL;
  ptr_new->right = NULL;
  //Parent
  ptr_new->parent = NULL;
  return ptr_new;
}

// TreeNode height
int tree_node_height (TreeNode *current) {
  int leftDepth, rightDepth;

  if (current != NULL) {
    leftDepth = tree_node_height(current->left);
    rightDepth = tree_node_height(current->right);
    if (leftDepth > rightDepth)
      return leftDepth + 1;
    else
      return rightDepth + 1;
  }
  return -1;
}

// Free memory of the nodes
void tree_node_free (TreeNode *current) {
  if (current != NULL) {
    tree_node_free(current->left);
    tree_node_free(current->right);
    free (current);
  }
}

// Finalize the tree
void tree_finalize (Tree *T) {
  tree_node_free (T->root);
}

// Initialize the tree
void tree_initialize (Tree *T) {
  T->root = NULL;
}

// Tree walk
void tree_walk (TreeNode *current, int depth) {
  if (current != NULL) {
    printf ("[%d] (%2d, %2d) ", depth, current->key, current->value);
    tree_walk (current->left, depth + 1);
    tree_walk (current->right, depth + 1);
  }
}

void insert_level_order(Tree *T, key, int value){
    if (T->root == NULL){
        T->root = tree_node_create(value)
        return;
    }
    List q;
    list_initialize(&q);
    q->
}

#endif
