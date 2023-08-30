#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Info structure
typedef struct info {
    int key;
    char value[20];
} Info;
// Default value for new node.
//Info Info_Default;

// Print Info
static inline void info_print (Info value) {
  printf ("[%d %s] ", value.key, value.value);
}

// Node definition
typedef struct node {
    Info value;
    bool isSentinel;
    struct node *next;
    struct node *prev;
} Node;

// List
typedef struct struct_list {
    Node *nil; //Sentinel node
    int size;
} List;

// Prototypes
// Node Functions
Node * node_create (Info value);

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
void list_insert (List *A, Info value, bool atBegin);
// Insert a node at a position
void list_insert_at (List *A, Info value, int position);
// Insert a new node before a target node.
void list_insert_before_target (List *A, Info value, Node *target);
// Print the list
void list_print (List * A);

// STACK functions
// Check if the stack is empty
bool stack_isEmpty (List *A);
// Remove the last item in the stack, return the value.
Info stack_pop (List *A);
// Push a number and its key
void stack_push (List *A, Info value);

//QUEUE
// Check if the queue is empty
bool queue_isEmpty (List *A);
// Enqueue
void queue_enqueue (List *A, Info value);
// Dequeue
Info queue_dequeue (List *A);
#endif // STACK
