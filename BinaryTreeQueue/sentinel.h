// Sentinel List
// Info has a pointer to a tree-node.

#ifndef _SENTINEL_H
#define _SENTINEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

// ListNode definition
typedef struct list_node
{
    TreeNode *ptr_tree_node;
    bool isSentinel;
    struct list_node *next;
    struct list_node *prev;
} ListNode;

// List
typedef struct struct_list
{
    ListNode *nil; //Sentinel node
    int size;
} List;

// Prototypes
// ListNode Functions
ListNode * node_create (TreeNode *ptr_tree_node);

// List Functions
// Get the node at a position
ListNode * list_get_at (List *A, int position);
// Delete a node
void list_delete (List *A, ListNode *target);
// Finalize a list
void list_finalize (List *A);
// Initialize the list
void list_initialize (List *A);
//Insert at the beginning or at the end.
void list_insert (List *A, TreeNode *ptr_tree_node, bool atBegin);
// Insert a node at a position
void list_insert_at (List *A, TreeNode *ptr_tree_node, int position);
// Insert a new node before a target node.
void list_insert_before_target (List *A, TreeNode *ptr_tree_node, ListNode *target);
// Print the list
void list_print (List * A);


// Functions
// ListNode Functions
ListNode * node_create (TreeNode *ptr_tree_node) {
  ListNode *ptr_new;
  ptr_new = (ListNode *)malloc(sizeof(ListNode));
  if (ptr_new == NULL) {
    printf("Out of memory\n");
    exit (1);
  }
  ptr_new->ptr_tree_node = ptr_tree_node;
  ptr_new->next = NULL;
  ptr_new->prev = NULL;
  ptr_new->isSentinel = false;
  return ptr_new;
}

// List Functions

// Delete a node
void list_delete (List *A, ListNode *target) {
    if (A->size == 0)
    {
        printf("List is empty\n");
        return;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    A->size = A->size - 1;
    free (target);
}

// Finalize a list
void list_finalize (List *A) {
  ListNode *i, *aux;
  i = A->nil->next;
  while (i != A->nil) {
    aux = i;
    i = i->next;
    free(aux);
  }
  free(A->nil);
  A->size = 0;
  A->nil = NULL;
}

// Get the node at a position
ListNode * list_get_at (List *A, int position) {
  ListNode *i;
  int j;
  for (i=A->nil->next, j=0; i!=A->nil && j<position; i=i->next, j++);
  return i;
}

// Initialize a list
void list_initialize (List *A) {
  A->nil = node_create(NULL);
  A->nil->isSentinel = true;
  A->nil->next = A->nil;
  A->nil->prev = A->nil;
  A->size = 0;
}

//Insert at the beginning or at the end.
void list_insert (List *A, TreeNode *ptr_tree_node, bool atBegin)
{
    if (atBegin)
        list_insert_before_target(A, ptr_tree_node, A->nil->next);
    else
		list_insert_before_target(A, ptr_tree_node, A->nil);
}

// Insert a node at a position
void list_insert_at (List *A, TreeNode *ptr_tree_node, int position) {
  list_insert_before_target(A, ptr_tree_node, list_get_at(A, position));
}

// Insert a new node before a target node.
void list_insert_before_target (List *A, TreeNode *ptr_tree_node, ListNode *target)
{
    ListNode *ptr_new;
    ptr_new = node_create(ptr_tree_node);
    // Insert before the reference node
    ptr_new->prev = target->prev;
    ptr_new->next = target;
    target->prev->next = ptr_new;
    target->prev = ptr_new;
    A->size++;
}

// Print the list
void list_print (List * A)
{
    ListNode *i;
    i = A->nil->next;
    while (!i->isSentinel)
    {
        printf("[%p](%d %d)\n", i->ptr_tree_node,
               i->ptr_tree_node->key, i->ptr_tree_node->value);
        i = i->next;
    }
}

#endif
