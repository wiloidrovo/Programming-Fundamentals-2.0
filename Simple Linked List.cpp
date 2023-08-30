#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct node{
  int key;
  int value;
  struct node *next;
} Node;

// List definition
typedef struct list{
  Node *head; //start
  Node *end;  //end
  int size;
} List;

// Node Functions
// Allocate memmory for a new node
Node *node_create(int key, int value);

// List Functions
// Initialize a list
void list_initialize (List *new_list);
// Insert a node in the first position
void list_insert_start (List *A, int key, int value);
// Insert a node in the last position
void list_insert_end (List *A, int key, int value);
// Print the list
void list_print (List *A);
// Insert a node in k position
void list_insert_k (List *A, int key, int value, int position);
// Search position
Node *List_search(List *A, int position);

// Main Function
int main(){
    List X;
    list_initialize(&X);
    list_insert_end(&X, 1, 25);
    list_insert_end(&X, 2, 30);
    list_insert_start(&X, 3, 35);
    list_insert_k(&X, 4, 40, 1);
    list_print(&X);
    return 0;
}

// Node Functions
// Allocate memmory for a new node
Node *node_create(int key, int value){
   Node *ptr_new;
   ptr_new = (Node *)malloc(sizeof(Node));
   if (ptr_new == NULL){
     printf ("Out of memmory");
     exit (1);
   }
   ptr_new->key = key;
   ptr_new->value = value;
   ptr_new->next = NULL;
   return ptr_new;
}

// List Functions
// Initialize a list
void list_initialize (List *new_list){
  new_list->head = NULL;
  new_list->end = NULL;
  new_list->size = 0;
}

// Insert a node in the first position
void list_insert_start (List *A, int key, int value){
  Node *new_node;
  new_node = node_create(key, value);
  if (A->head == NULL){ // First case: list is empty
    A->head = new_node;
    A->end = new_node;
  }
  else{ //Second case: list is not empty
    new_node->next = A->head;
    A->head = new_node;
  }
  A->size++;
}

// Insert a node in the last position
void list_insert_end (List *A, int key, int value){
  Node *new_node;
  new_node = node_create(key, value);
  if (A->head == NULL){ // First case: list is empty
    A->head = new_node;
    A->end = new_node;
  }
  else { //Second case: list is not empty
    A->end->next = new_node;
    A->end = new_node;
  }
  A->size++;
}

// Insert a node in k position
void list_insert_k (List *A, int key, int value, int position){
	Node *new_node, * target;
	new_node = node_create(key, value);
	if (A->head == NULL){ // First case: list is empty
    	A->head = new_node;
    	A->end = new_node;
	}
	else { // Second case: list is not empty	
		target = List_search(A, position);
		if (target == NULL){
			printf("Position does not exist \n");
			return;
		}
		new_node->next = target->next;
		target->next = new_node;
		if (target == A->end){
			A->end = new_node;
		}
	}
}

// Search position
Node *List_search(List *A, int position){
	Node *i;
	int c = 0;
	i = A->head; // Start in the first node
	while (i != NULL && c != position){
		i = i->next;
		c++;
	}
	return i;
}


// Print the list
void list_print (List *A){
  Node *i;
  i = A->head; // Start in the first node
  while(i != NULL){
    printf ("[%d, %d] ", i->key, i->value); //Print current node
    i = i->next; // Go to the next node
  }
  printf ("\n");
}