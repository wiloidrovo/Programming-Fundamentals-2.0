#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct node {
  int key;
  int value;
  struct node *next;
  struct node *prev;
} Node;

// List definition
typedef struct list{
  Node *head; //start
  Node *end;  //end
  int size;
} List;

// Node Functions
// Allocate memmory for a new node
Node * node_create (int key, int value);

// List Functions
// Delete a target node from the list
void list_delete (List *A, Node *target);
// Delete a node at a position from the list
void list_delete_at (List *A, int position);
// Finalize a list
void list_finalize (List *A);
// Get the node at a position
Node *list_get_at (List *A, int position);
// Initialize a list
void list_initialize (List *new_list);
// Insert a node at a position
void list_insert_at (List *A, int key, int value, int position);
// Insert a node before or after a target position
void list_insert_in (List *A, int key, int value, Node *target, bool before);
// Insert a node in the first position
void list_insert_start (List *A, int key, int value);
// Insert a node in the last position
void list_insert_end (List *A, int key, int value);
// Print the list
void list_print (List *A);
// Print the inverted list
void list_print_inv (List *A);

// Main Function
int main()
{
    List X;
    list_initialize(&X);
    list_insert_end(&X, 1, 25);
    list_insert_end(&X, 2, 30);
    list_insert_end(&X, 3, 35);
    list_insert_at(&X, 4, 40, 1);
    //list_delete_at(&X, 2);
    printf ("List: ");
    list_print(&X);
    printf ("Inv. List: ");
    list_print_inv(&X);
    //list_finalize(&X);
    return 0;
}

// Node Functions
// Allocate memmory for a new node
Node * node_create (int key, int value) {
   Node *ptr_new;
   ptr_new = (Node *) malloc (sizeof(Node));
   if (ptr_new == NULL) {
     printf ("Out of memmory");
     exit (1);
   }
   ptr_new->key = key;
   ptr_new->value = value;
   ptr_new->next = NULL;
   ptr_new->prev = NULL;
   return ptr_new;
}

// List Functions
// Delete a target node from the list
void list_delete (List *A, Node *target) {
  Node *prev, *next;
  prev = target->prev;
  next = target->next;
  if (target != A->head && target != A->end) {
	prev->next = next;
	next->prev = prev;
  }
  else {
  	if (target == A->head){  // Delete the first node
  		A->head = next;
  		next->prev = NULL;
	  }
	else{  // Delete the last node
		A->end = prev;
		prev->next = NULL;
	}
  }
  free(target);
  A->size--;
}

// Delete a node at a position from the list
void list_delete_at (List *A, int position) {
  Node *target = list_get_at(A, position);
  if (target != NULL) {
    list_delete(A, target);
  }
  else {
    printf ("The position %d does not exist.\n", position);
  }
}

// Finalize a list
void list_finalize (List *A) {
  Node *i, *aux;
  i = A->head;
  while (i != NULL) {
    aux = i;
    i = i->next;
    free (aux);
  }
}

// Get the node at a position
Node * list_get_at (List *A, int position) {
  Node *i;
  int j;
  for (i=A->head, j=0; i!=NULL && j<position; i=i->next, j++);
  return i;
}

// Initialize a list
void list_initialize (List *new_list) {
  new_list->head = NULL;
  new_list->end = NULL;
  new_list->size = 0;
}

// Insert a node at a position
void list_insert_at (List *A, int key, int value, int position) {
  list_insert_in(A, key, value, list_get_at(A, position), false);
}

// Insert a node before or after a target position
void list_insert_in (List *A, int key, int value, Node *target, bool before) {
  Node *new_node;
  new_node = node_create(key, value);
  if (A->head == NULL) { // First case: list is empty
    A->head = new_node;
    A->end = new_node;
  }
  else { //Second case: list is not empty
    if (before) {
      new_node->next = target;
      if (target != A->head) {
        // When target is A->head target->prev == NULL
        target->prev->next = new_node;
        new_node->prev = target->prev;
      }
      else {
        A->head = new_node;
      }
      target->prev = new_node;
    }
    else {
      new_node->prev = target;
      if (target != A->end) {
        // When target is A->head target->next == NULL
        target->next->prev = new_node;
        new_node->next = target->next;
      }
      else {
        A->end = new_node;
      }
      target->next = new_node;
    }
  }
  A->size++;
}

// Insert a node in the first position
void list_insert_start (List *A, int key, int value) {
  Node *new_node;
  new_node = node_create(key, value);
  if (A->head == NULL) { // First case: list is empty
    A->head = new_node;
    A->end = new_node;
  }
  else { //Second case: list is not empty
    new_node->next = A->head;
    A->head->prev = new_node;
    A->head = new_node;
  }
  A->size++;
}

// Insert a node in the last position
void list_insert_end (List *A, int key, int value){
  Node *new_node;
  new_node = node_create(key, value);
  if (A->head == NULL) { // First case: list is empty
    A->head = new_node;
    A->end = new_node;
  }
  else { //Second case: list is not empty
    A->end->next = new_node;
    new_node->prev = A->end;
    A->end = new_node;
  }
  A->size++;
}

// Print the list
void list_print (List *A) {
  Node *i;
  i = A->head; //Start in the first node
  while(i != NULL) {
    printf ("[%d, %d] ", i->key, i->value); //Print current node
    i = i->next; //Go to the next node
  }
  printf ("\n");
}

// Print the inverted list
void list_print_inv (List *A) {
  Node *i;
  i = A->end; //Start in the last node
  while(i != NULL) {
    printf ("[%d, %d] ", i->key, i->value); //Print current node
    i = i->prev; //Go to the next node
  }
  printf ("\n");
}