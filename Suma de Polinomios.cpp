#include <stdio.h>
#include <stdlib.h>

// Monomial definition
typedef struct monomial{
	float coef;
	int A; // x exponent
	int B; // y exponent
	int C; // z exponent
} Monomial;

// Node definition
typedef struct node{
	Monomial value;
	struct node *next;
} Node;

// List definition
typedef struct list{
	Node *head;
	Node *tail;
	int size;
} List;

// Node function
// Allocate memmory for a new node
Node *create_node(Monomial value);
// List functions
// Initialize a list
void list_initialize(List *A);
// Delete a target node from the list
int list_delete(List *A, Node *target);
// Insert a new node in the last position
void list_insert_end(List *A, Monomial value);
// Print the list
void print_list(List *A);
// Search a monomial by the exponents
Node *search(List *A, Monomial target);
// Process
void process(List *P1, List *P2, List *P3, float k);

// Main Function
int main(void){
	List P1, P2, P3;
	Monomial m1, m2, m3, m4;
	list_initialize(&P1);
	list_initialize(&P2);
	list_initialize(&P3);
	
	// P1
	printf("Datos para el primer polinomio.\n");
	printf("Ingrese los valores del primer monomio: \n");
	scanf("%f %d %d %d", &m1.coef, &m1.A, &m1.B, &m1.C);
	printf("Ingrese los valores del segundo monomio: \n");
	scanf("%f %d %d %d", &m2.coef, &m2.A, &m2.B, &m2.C);
	printf("Ingrese los valores del tercer monomio: \n");
	scanf("%f %d %d %d", &m3.coef, &m3.A, &m3.B, &m3.C);
	printf("Ingrese los valores del cuarto monomio: \n");
	scanf("%f %d %d %d", &m4.coef, &m4.A, &m4.B, &m4.C);
	list_insert_end(&P1, m1);
	list_insert_end(&P1, m2);
	list_insert_end(&P1, m3);
	list_insert_end(&P1, m4);
	
	// P2
	printf("Datos para el segundo polinomio.\n");
	printf("Ingrese los valores del primer monomio: \n");
	scanf("%f %d %d %d", &m1.coef, &m1.A, &m1.B, &m1.C);
	printf("Ingrese los valores del segundo monomio: \n");
	scanf("%f %d %d %d", &m2.coef, &m2.A, &m2.B, &m2.C);
	printf("Ingrese los valores del tercer monomio: \n");
	scanf("%f %d %d %d", &m3.coef, &m3.A, &m3.B, &m3.C);
	printf("Ingrese los valores del cuarto monomio: \n");
	scanf("%f %d %d %d", &m4.coef, &m4.A, &m4.B, &m4.C);
	list_insert_end(&P2, m1);
	list_insert_end(&P2, m2);
	list_insert_end(&P2, m3);
	list_insert_end(&P2, m4);
	/*
	// P1
	1 2 0 0
	1 1 1 0
	1 0 2 0
	
	// P2
	1 3 0 0
	-1 1 1 0
	1 0 2 0
	1 0 0 1
	*/
	printf("P1: ");
	print_list(&P1);
	printf("\nP2: ");
	print_list(&P2);
  
	process(&P1, &P2, &P3, 1);
  
	printf("\nP1+P2= ");
	print_list(&P3);
return 0;
}

// Allocate memmory for a new node
Node *create_node(Monomial value){
	Node *ptr_new;
	ptr_new = (Node *)malloc(sizeof(Node));
	if (ptr_new == NULL){
		printf ("Out of memmory");
		exit(1);
	}
	ptr_new->value = value;
	ptr_new->next = NULL;
	return ptr_new;	
}

// Initialize a list
void list_initialize(List *A){
	A->head = NULL;
	A->tail = NULL;
	A->size = 0;
}

// Insert a node in the last position
void list_insert_end (List *A, Monomial value){
	Node *new_node;
	new_node = create_node(value);
	if (A->head == 0){  // First case: list is empty
		A->head = new_node;
		A->tail = new_node;
	}
	else {  // Second case: list is not empty
		A->tail->next = new_node;
		A->tail = new_node;
	}
	A->size++;
}

// Search a monomial by the exponents
Node *search(List *A, Monomial target){
	Node *i;
	i = A->head;  // Start in the first node
	while (i != NULL){
		if (i->value.A == target.A && i->value.B == target.B && i->value.C == target.C){
			return i;
		}
		i = i->next;
	}
	return i;
}

// Delete a target node
int list_delete(List *A, Node *target){
	Node *aux = NULL;
	Node *i = A->head;  // Start in the first node
	while (i != NULL){	
		if (i == target){ // I found the target
			if (aux == NULL){ // Delete the first element
				if (A->size == 1){ // If it is the only element
					free(i);
					A->head = NULL;
					A->tail = NULL;
				}
				else{
					A->head = i->next;
					free(i);
				}
			}
			else{
				aux->next = i->next;
				free (i);		
			}
			return 1; // Deleted
		}
		aux = i;
		i = i->next;
	}
	return 0; // Not found
}

// Process
void process(List *P1, List *P2, List *P3, float k){
	Node *i, *ptr;
	Monomial m;
	// 1) Iterate P1
	i = P1->head;
	while (i != NULL){
		ptr = search(P2, i->value);
		if (ptr == NULL){ //No exist
			list_insert_end(P3, i->value);
		}		
		else { //It exists
    		// 2) Operation P1 + kP2
			m = i->value;
			m.coef += k*(ptr->value.coef);
			if (m.coef != 0){
				list_insert_end(P3, m);
			}
			// 3) Delete from P2
			list_delete(P2, ptr);
		}
		i = i->next;
	}
	// Insert from p2 the monomials that are missing
	i = P2->head;
	while (i != NULL){
		i->value.coef *= k;
		list_insert_end(P3, i->value);
		i = i->next;
	}
}

// Print 
void print_list(List *A){
	Node *i;
	i = A->head;
	while (i != NULL){
		printf("+(%0.02f)x^%d y^%d z^%d ", i->value.coef, i->value.A, i->value.B, i->value.C);  
		i = i->next;
	}
}