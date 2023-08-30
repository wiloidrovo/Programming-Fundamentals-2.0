#include "stackqueue.h"

// Functions
// Node Functions
Node * node_create (Info value) {
  Node *ptr_new;
  ptr_new = (Node *)malloc(sizeof(Node));
  if (ptr_new == NULL) {
    printf("Out of memory\n");
    exit (1);
  }
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
    Info Info_Default;
    A->nil = node_create(Info_Default);
    A->nil->isSentinel = true;
    A->nil->next = A->nil;
    A->nil->prev = A->nil;
    A->size = 0;
}

//Insert at the beginning or at the end.
void list_insert (List *A, Info value, bool atBegin) {
    if (atBegin)
        list_insert_before_target(A, value, A->nil->next);
    else
		list_insert_before_target(A, value, A->nil);
}

// Insert a node at a position
void list_insert_at (List *A, Info value, int position) {
  list_insert_before_target(A, value, list_get_at(A, position));
}

// Insert a new node before a target node.
void list_insert_before_target (List *A, Info value, Node *target) {
    Node *ptr_new;
    ptr_new = node_create(value);
    // Insert before the reference node
    ptr_new->prev = target->prev;
    ptr_new->next = target;
    target->prev->next = ptr_new;
    target->prev = ptr_new;
    A->size++;
}

// Print the list
void list_print (List * A) {
    Node *i;
    i = A->nil->next;
    while (!i->isSentinel)
    {
        //printf("[%c] ", i->value); //Update with Info
        info_print(i->value);
        i = i->next;
    }
}

// STACK functions
// Check if the stack is empty
bool stack_isEmpty (List *A) {
    return (A->size == 0);
}

// Remove the last item in the stack, return the value.
Info stack_pop (List *A) {
    Info copy;
    copy = A->nil->prev->value;
    list_delete (A, A->nil->prev); //Remove the last node
    return copy;
}

// Push a number and its key
void stack_push (List *A, Info value) {
    list_insert (A, value, false); //Insert in the last node
}


//QUEUE
// Check if the queue is empty
bool queue_isEmpty (List *A) {
    return (A->size == 0);
}
// Enqueue
void queue_enqueue (List *A, Info value) {
    list_insert (A, value, false); //Insert in the last node
}
// Dequeue
Info queue_dequeue (List *A) {
    Info copy;
    copy = A->nil->next->value;
    list_delete (A, A->nil->next); //Remove the first node
    return copy;
}
