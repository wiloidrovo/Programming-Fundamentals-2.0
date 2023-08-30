#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct node
{
    int key;
    int value;
    bool isSentinel;
    struct node *next;
    struct node *prev;
} Node;

// List
typedef struct struct_list
{
    Node *nil; //Sentinel node
    int size;
} List;

// Prototypes
// Node Functions
Node * node_create (int key, int value);

// List Functions
// Get the node at a position
Node * list_get_at (List *A, int position);
// Delete a node
void list_delete (List *A, Node *target);
// Finalize a list
void list_finalize (List *A);
// Initialize the list
void list_initialize (List *A);
//Insert at the beginning or at the end.
void list_insert (List *A, int key, int value, bool atBegin);
// Insert a node at a position
void list_insert_at (List *A, int key, int value, int position);
// Insert a new node before a target node.
void list_insert_before_target (List *A, int key, int value, Node *target);
// Print the list
void list_print (List * A);

// Main function
int main()
{
    List temp;
    list_initialize(&temp);
    list_insert(&temp, 10, 11, false);
    list_insert(&temp, 20, 12, false);
    list_insert(&temp, 30, 13, false);
    list_delete(&temp, list_get_at(&temp, 2));
    list_insert_at(&temp, 15, 14, 1);
    list_print(&temp);
    list_finalize(&temp);
    return 0;
}

// Functions
// Node Functions
Node * node_create (int key, int value) {
  Node *ptr_new;
  ptr_new = (Node *)malloc(sizeof(Node));
  if (ptr_new == NULL) {
    printf("Out of memory\n");
    exit (1);
  }
  ptr_new->key = key;
  ptr_new->value = value;
  ptr_new->next = NULL;
  ptr_new->prev = NULL;
  ptr_new->isSentinel = false;
  return ptr_new;
}

// List Functions

// Delete a node
void list_delete (List *A, Node *target) {
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
  Node *i, *aux;
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
Node * list_get_at (List *A, int position) {
  Node *i;
  int j;
  for (i=A->nil->next, j=0; i!=A->nil && j<position; i=i->next, j++);
  return i;
}

// Initialize a list
void list_initialize (List *A) {
  A->nil = node_create(0, 0);
  A->nil->isSentinel = true;
  A->nil->next = A->nil;
  A->nil->prev = A->nil;
  A->size = 0;
}

//Insert at the beginning or at the end.
void list_insert (List *A, int key, int value, bool atBegin)
{
    if (atBegin)
        list_insert_before_target(A, key, value, A->nil->next);
    else
		list_insert_before_target(A, key, value, A->nil);
}

// Insert a node at a position
void list_insert_at (List *A, int key, int value, int position) {
  list_insert_before_target(A, key, value, list_get_at(A, position));
}

// Insert a new node before a target node.
void list_insert_before_target (List *A, int key, int value, Node *target)
{
    Node *ptr_new;
    ptr_new = node_create(key, value);
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
    Node *i;
    i = A->nil->next;
    while (!i->isSentinel)
    {
        printf("[%d, %d] ", i->key, i->value);
        i = i->next;
    }
}