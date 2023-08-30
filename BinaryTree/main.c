#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary node definition
typedef struct node {
  // Info
  int key;
  int value;
  // Sons
  struct node *left;
  struct node *right;
  // Parent
  struct node *parent;
} Node;

// Tree definition
typedef struct tree {
  Node *root;
} Tree;

// Create a new node
Node * node_create (int nkey, int nvalue) {
  Node * ptr_new;
  ptr_new = (Node *) malloc (sizeof(Node));
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

// Node height
int node_height (Node *current) {
  int leftDepth, rightDepth;

  if (current != NULL) {
    leftDepth = node_height(current->left);
    rightDepth = node_height(current->right);
    if (leftDepth > rightDepth)
      return leftDepth + 1;
    else
      return rightDepth + 1;
  }
  return -1;
}

// Free memory of the nodes
void node_free (Node *current) {
  if (current != NULL) {
    node_free(current->left);
    node_free(current->right);
    free (current);
  }
}

// Finalize the tree
void tree_finalize (Tree *T) {
  node_free (T->root);
}

// Initialize the tree
void tree_initialize (Tree *T) {
  T->root = NULL;
}

// Tree walk
void tree_walk (Node *current, int depth) {
  if (current != NULL) {
    printf ("[%d] (%2d, %2d) ", depth, current->key, current->value);
    tree_walk (current->left, depth + 1);
    tree_walk (current->right, depth + 1);
  }
}

// Sum of the values
int sum (Node *current, int depth) {
  int i, s = 0;
  if (current != NULL) {
     for (i=0; i<=depth; i++){
        //s+=current->value;
        s+=sum(current->value, depth + 1);
      }
  //printf("\n%d", s);
  return s;
}
}

// Sum 2
int sum2 (Node *current) {
    if (current != NULL) {
        return current->value + sum2(current->left) + sum2(current->right);
    }
    return 0;
}

// Main function
int main()
{
  Tree T;
  tree_initialize (&T);

  // Manual Insertion
  T.root = node_create(1, 10);
  T.root->left = node_create (2, 20);
  T.root->right = node_create (3, 30);
  T.root->left->right = node_create (5, 50);
  T.root->right->left = node_create (6, 60);
  T.root->right->right = node_create (7, 70);
  T.root->left->right->left = node_create (10, 100);
  printf ("Root height = %d\n", node_height(T.root));
  printf ("Tree walk\n");
  tree_walk(T.root, 0);
  sum(T.root, 0);
  sum2(T.root);
  tree_finalize (&T);
  return 0;
}
