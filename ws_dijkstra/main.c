/*
 * Dijkstra Algorithm with adjacency lists.
 */
/*
Example
Input
-------
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0 4
*/

#include "sentinel.h"
#define INF 10000

typedef struct graph{
    List *array; //array of lists
    int n; // number of vertices
    int *d;  // array of accumulated weights
    int *pi; // array of sources
    int *Q;  // array of visited nodes
}Graph;

//Extract the node with the minimum accumulated weight
int extract_minimum (Graph *A);
//Initialize the graph
void graph_initialize (Graph *A, int n);
//Free graph memory
void graph_finalize (Graph *A);
//Print a graph
void graph_print (Graph *A);
//Print path
void print_path (int *pi, int s, int e);
//Update accumulated weights.
void relax (Graph *A, int u, int v, int w);
//Check if there are nodes to explore
bool there_are_nodes (Graph *A);

// Main function
int main()
{
    int n, m, i, a, b, w, s, e, u;
    Node *j;
    Graph A;
    //Read number of vertices and edges
    scanf("%d %d", &n, &m);
    graph_initialize(&A, n);  // Dijkstra initialization
    //Read edges
    for (i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &w);
        list_insert(&A.array[a], b, w, false);
        list_insert(&A.array[b], a, w, false);
    }
    scanf("%d %d", &s, &e);
    A.d[s]=0; // Accumulated weight of the first node

    while (there_are_nodes(&A)) {
      u = extract_minimum(&A);
      A.Q[u] = 1; //Exploring
      //Stop when u is equal to target node
      if (u == e) {
        printf ("Target %d found\n", u);
        break;
      }
      printf ("Exploring %d\n", u);
      //for each vertex from u
      for (i = 0, j = A.array[u].nil->next; i < A.array[u].size; i++, j = j->next)
        relax(&A, u, j->id, j->weight);

      graph_print(&A);
      system("pause");
    }

    printf ("Final weights\n");
    graph_print(&A);
    print_path(A.pi, s, e);
    graph_finalize(&A);
    return 0;
}

//Extract the node with the minimum accumulated weight
int extract_minimum(Graph *A) {
  int i, min = INF, position = -1;
  for (i = 0; i < A->n; i++) {
    if (A->d[i] < min && A->Q[i] == 0) {
      min = A->d[i];
      position = i;
    }
  }
  return position; //-1 means all explored.
}

//Initialize the graph
void graph_initialize (Graph *A, int n){
    int i;
    A->n=n;
    A-> array= (List *) malloc(sizeof(List)*n);
    A->d=(int *) malloc(sizeof(int)*n);
    A->pi=(int *) malloc(sizeof(int)*n);
    A->Q=(int *) malloc(sizeof(int)*n);
    if (A->array ==NULL || A->d==NULL || A->pi==NULL || A->Q == NULL ){
        printf("Out of memory");
        exit(1);
    }
    for ( i=0; i<n; i++){// Initialize each vertex
        list_initialize(&A->array[i]);
         A->d[i]=INF; //Inf.
         A->pi[i]=-1; //Not connected
         A->Q[i]=0; //Not explored
    }
}

//Free graph memory
void graph_finalize (Graph *A) {
    int i;
    for ( i=0; i<A->n; i++)// Finalize each vertex
        list_finalize(&A->array[i]);
    free (A->array);
    free (A->d);
    free (A->pi);
    free (A->Q);
}


//Print the Graph
void graph_print(Graph *A){
    int i;
     for (i=0; i< A->n; i++){
        printf("(%2d) [d = %5d, pi = %2d, Q = %d] ",
               i, A->d[i], A->pi[i], A->Q[i]);
        list_print(&A->array[i]);
        printf("\n");
     }
}

//Print path
void print_path (int *pi, int s, int e) {
    printf("%d ", s);
    if (e != s){
        print_path(pi, s, pi[e]);
    }
}

//Update accumulated weights.
void relax (Graph *A, int u, int v, int w) {
    if (A->d[v]>A->d[u]+w){
        A->d[v]=A->d[u]+w;
        A->pi[v]=u;
    }
}

//Check if there are nodes to explore
bool there_are_nodes(Graph *A) {
  int i;
  for (i=0; A->n; i++) {
    if (A->Q[i] == 0) return true;
  }
  return false;
}
