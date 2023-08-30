#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct node{
    int key; // id
    int value; // weight
    bool isSentinel;
    struct node *next;
    struct node *prev;
} Node;

// List
typedef struct struct_list{
    Node *nil; //Sentinel node
    int size;
} List;

// 
typedef struct graph{
	List *array; // Array of lists
	int n; // number of vertices
	int *d; // array of weigths
	int *pi;
	int *Q; // array of visited nodes
} Graph;

// Prototypes
// Node Functions
Node * node_create (int key, int value);

// Initialize the graph
void graph_initialize (Graph *a, int n); 

// Print a graph
void graph_print(Graph *A);

// Check if there are nodes to explore
bool there_are_nodes(Graph *A);

// Extract the node with the minimum acumulated weight
int extract_minimum(Graph *A);

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
int main(void){
	int n, m, i, a, b, w, s, e, u; // (s: vertice origen)  (e: vertice destino)
    Graph A;
    // Read number of vertices
    scanf("%d %d", &n, &m);
    graph_initialize(&A, n); // Disjktra initialization
    // Read edges
    for (i=0; i<m; i++){
    	scanf("%d %d %d", &a, &b, &w);
    	list_insert(&A.array[a], b, w, false);
    	list_insert(&A.array[b], a, w, false);
	}
	scanf("%d %d", &s, &e);
	A.d[s] = 0; // Acumulated weight of the first node
    graph_print(&A);
    while (there_are_nodes(&A)){
    	u = extract_minimum(&A);
    	printf("Exploring %d\n", u);
	break;
	}
    return 0;
}

// Initialize the graph
void graph_initialize (Graph *A, int n){
	int i;
	A->n = n;
	A->array = (List *) malloc(sizeof(List) * n); // Create the array of lists
	A->d = (int *) malloc(sizeof(int) * n);
	A->pi = (int *) malloc(sizeof(int) * n);
	A->Q = (int *) malloc(sizeof(int) * n);
	if (A->array == NULL || A->d == NULL || A->pi == NULL || A->Q == NULL){
		printf("Out of memory");
		exit(1);
	}
	for (i=0; i<n; i++){ // Initialize each vertex
		list_initialize(&A->array[i]);
		A->d[i] = 10000;
		A->pi[i] = -1;
		A->Q[i] = 0;
	}
}

// Print a graph
void graph_print(Graph *A){
	int i, max=A->array[0].size;
	for (i=0; i<A->n; i++){
		//printf("(%d) size = %d ", i, A->array[i].size);
		printf("(%d) peso acumulado = %d\n pi = %d\n", i, A->d[i], A->pi[i]);
		if (A->array[i].size>max){
			max = A->array[i].size;
			//printf("aqui esta ");
		}
		list_print(&A->array[i]);
		printf("\n");
	}
	printf("max = %d\n", max);
}

// Functions
// Node Functions
Node * node_create (int key, int value){
  Node *ptr_new;
  ptr_new = (Node *)malloc(sizeof(Node));
  if (ptr_new == NULL){
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
void list_delete (List *A, Node *target){
    if (A->size == 0){
        printf("List is empty\n");
        return;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    A->size = A->size - 1;
    free (target);
}

// Finalize a list
void list_finalize (List *A){
	
	Node *i, *aux;
	i = A->nil->next;
	while (i != A->nil){
		aux = i;
		i = i->next;
		free(aux);
	}
	free(A->nil);
	A->size = 0;
	A->nil = NULL;
}

// Get the node at a position
Node * list_get_at (List *A, int position){
	Node *i;
	int j;
	for (i=A->nil->next, j=0; i!=A->nil && j<position; i=i->next, j++);
	return i;
}

// Initialize a list
void list_initialize (List *A){
	A->nil = node_create(0, 0);
	A->nil->isSentinel = true;
	A->nil->next = A->nil;
	A->nil->prev = A->nil;
	A->size = 0;
}

//Insert at the beginning or at the end.
void list_insert (List *A, int key, int value, bool atBegin){
    if (atBegin){
        list_insert_before_target(A, key, value, A->nil->next);
    }
    else{
		list_insert_before_target(A, key, value, A->nil);
	}
}

// Insert a node at a position
void list_insert_at (List *A, int key, int value, int position){
	list_insert_before_target(A, key, value, list_get_at(A, position));
}

// Insert a new node before a target node.
void list_insert_before_target (List *A, int key, int value, Node *target){
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
void list_print (List * A){
    Node *i;
    i = A->nil->next;
    while (!i->isSentinel){
        printf("[%d, %d] ", i->key, i->value);
        i = i->next;
    }
}

// Check if there are nodes to explore
bool there_are_nodes(Graph *A){
	int i;
	for (i=0; A->n; i++){
		if (A->Q[i] == 0) return true;
	}
	return false;
}

// Extract the node with the minimum acumulated weight
int extract_minimum(Graph *A){
	int i, min = A->d[0], position = 0;
	for (i=0; i<A->n; i++){
		if (A->d[i]<min && A->Q[i] == 0){
			min = A->d[i];
			position = i;
		}
	}
	return position;
}