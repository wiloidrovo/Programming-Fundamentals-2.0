/*
 * Prim's Algorithm with adjacency lists.
 */
/*
Example
Input
-------
0 1 2 3 4 5 6 7 8
a b c d e f g h i
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
0
*/


#include "sentinel.h"

//Out infinite definition
#define INF 10000

//Graph definition
typedef struct graph{
    List *array; //array of lists
    int n; // number of vertices
    int *key;  // array of accumulated weights
    int *pi; // array of sources
    int *Q;  // array of visited nodes
}Graph;

//Extract the node with the minimum accumulated weight
int extract_minimum(Graph *A);
// Initialize graph for the algorithm
// Input: Graph A and number of vertices n.
void graph_initialize (Graph *A, int n);
//Free graph memory
void graph_finalize (Graph *A);
//Print the Graph
void graph_print(Graph *A);
// Read a weighted graph
void graph_read_weights (Graph *A, int m);
//Check if there are nodes to explore
bool there_are_nodes(Graph *A);

int main()
{
    int n, m, r, u, v, i;
    Node *j;
    Graph A;
    // Read number of vertices and edges
    scanf("%d %d", &n, &m);
    graph_initialize(&A, n);  // Dijkstra initialization
    graph_read_weights(&A, m);
    // read root
    scanf ("%d", &r);
    A.key[r] = 0; // Accumulated weight of the first node

    while (there_are_nodes(&A)) {
      u = extract_minimum(&A);
      if (u == -1) break; // No more nodes
      A.Q[u] = 1; //Exploring
      printf ("Exploring %d\n", u);
      //for each vertex from u
      for (i = 0, j = A.array[u].nil->next; i < A.array[u].size; i++, j = j->next) {
        v = j->id;
        if (A.Q[v]==0 && j->weight < A.key[v]) {
            A.pi[v] = u;
            A.key[v] = j->weight;
        }
      }
      graph_print(&A);
      system("pause"); //read -rsp $'Press enter to continue...\n'
    }
    printf ("Result\n");
    graph_print(&A);
    graph_finalize(&A);
    return 0;
}

//Extract the node with the minimum accumulated weight
int extract_minimum(Graph *A) {
  int i, min = INF, position = -1;
  for (i = 0; i < A->n; i++) {
    if (A->key[i] < min && A->Q[i] == 0) {
      min = A->key[i];
      position = i;
    }
  }
  return position; //-1 means all explored.
}

// Initialize graph for the algorithm
// Input: Graph A and number of vertices n.
void graph_initialize (Graph *A, int n) {
    int i;
    A->n = n;
    A->array = (List *)malloc(sizeof(List)*n);
    A->key = (int *)malloc(sizeof(int)*n);
    A->pi = (int *)malloc(sizeof(int)*n);
    A->Q = (int *)malloc(sizeof(int)*n);
    if (A->array == NULL || A->key==NULL || A->pi==NULL || A->Q == NULL){
        printf("Out of memory");
        exit(1);
    }
    for ( i = 0; i < A->n; i++){// Initialize each vertex
        list_initialize(&A->array[i]);
         A->key[i]=INF; //Inf.
         A->pi[i]=-1; //Not connected
         A->Q[i]=0; //Not explored
    }
}

//Free graph memory
void graph_finalize (Graph *A) {
    int i;
    for ( i = 0; i < A->n; i++ )// Finalize each vertex
        list_finalize(&A->array[i]);
    free (A->array);
    free (A->key);
    free (A->pi);
    free (A->Q);
}

//Print the Graph
void graph_print(Graph *A){
    int i;
     for (i=0; i< A->n; i++){
        printf("(%2d) [key = %5d, pi = %2d, Q = %d] ",
               i, A->key[i], A->pi[i], A->Q[i]);
        list_print(&A->array[i]);
        printf("\n");
     }
}

// Read a weighted graph
// Graph A and number of edges m.
// format: vertex-source a vertex-destination b weight(a,b)
void graph_read_weights (Graph *A, int m) {
    int i, a, b, w;
    //Read edges
    for (i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &w);
        list_insert(&A->array[a], b, w, false);
        list_insert(&A->array[b], a, w, false);
    }
}

//Check if there are nodes to explore
bool there_are_nodes(Graph *A) {
  int i;
  for (i=0; i < A->n; i++)
    if (A->Q[i] == 0)
      return true;
  return false;
}
