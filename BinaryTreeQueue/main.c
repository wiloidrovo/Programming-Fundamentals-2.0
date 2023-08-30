#include "tree.h"
#include "sentinel.h"

// Main function - example of tree.
int main()
{
  Tree T;
  List L;
  tree_initialize (&T);
  list_initialize (&L);

  // Manual Insertion
  T.root = tree_node_create(1, 10);
  list_insert (&L, T.root, false);
  T.root->left = tree_node_create (2, 20);
  list_insert (&L, T.root->left, false);
  T.root->right = tree_node_create (3, 30);
  list_insert (&L, T.root->right, false);
  T.root->left->right = tree_node_create (5, 50);
  list_insert (&L, T.root->left->right, false);
  T.root->right->left = tree_node_create (6, 60);
  list_insert (&L, T.root->right->left, false);
  T.root->right->right = tree_node_create (7, 70);
  list_insert (&L, T.root->right->right, false);
  T.root->left->right->left = tree_node_create (10, 100);
  list_insert (&L, T.root->left->right->left, false);
  printf ("Root height = %d\n", tree_node_height(T.root));
  printf ("Tree walk\n");
  tree_walk(T.root, 0);
  printf ("List\n");
  list_print(&L);
  tree_finalize (&T);
  list_finalize (&L);
  return 0;
}


