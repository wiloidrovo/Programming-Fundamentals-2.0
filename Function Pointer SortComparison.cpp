#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Bubble sort
void bubblesort (int A[], int n);
//Create array of random numbers from 0 to 99
int * createArray (int n);
//Create an array copying the values from another array.
int * createCopyArray (int A[], int n);
//Insertion sort
void insertionsort (int A[], int n);
//Print array
void printArray (int A[], int n);
//Sort and print an array
void sortArrayPrint (int A[], int n, char *name, void (*sortMethod)(int B[], int n));
//Measure running time
double measureRunningTime (int A[], int n, void (*sortMethod)(int B[], int n));

/*
// Main Function
int main()
{
  int a[]={4, 2, 7, 5, 8, 1, 3};
  int b[]={4, 2, 7, 5, 8, 1, 3};
  int n=7;
  printf("a = ");
  printArray(a, n);
  printf("Insertion sort\n");
  insertionsort(a, n);
  printf("a = ");
  printArray(a, n);
  printf ("\n");
  printf("b = ");
  printArray(b, n);
  printf("Bubble sort\n");
  bubblesort(b, n);
  printf("b = ");
  printArray(b, n);
  return 0;
}
*/


// Main Function
int main()
{
  int a[]={4, 2, 7, 5, 8, 1, 3};
  int b[]={4, 2, 7, 5, 8, 1, 3};
  int n=7;

  sortArrayPrint (a, n, "Bubble sort", bubblesort);
  printf("\n");
  sortArrayPrint (b, n, "Insertion sort", insertionsort);
  return 0;
}

/*
// Main function
int main(void) {
  long int i, l, n, step;
  int *A, *B;
  step = 10000;
  n = 10;
  l = n * step + step;
  for (i = step; i < l; i+=step) {
    printf ("Size = %ld ", i);
    A = createArray(i);
    B = createCopyArray(A, i);
    printf ("Bubble sort %0.04f[s] Insertion sort %0.4f[s]\n",
            measureRunningTime(A, i, bubblesort),
            measureRunningTime(B, i, insertionsort));
    free (A); free (B);
  }
  return 0;
}
*/

//Bubble sort
void bubblesort (int A[], int n) {
  int i, j, aux;
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        aux = A[j - 1];
        A[j - 1] = A[j];
        A[j] = aux;
      }
    }
  }
}

//Create array of random numbers from 0 to 99
int * createArray (int n) {
  int *A, i;
  A = (int *) malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    A[i] = rand()%100;
  }
  return A;
}

//Create an array copying the values from another array.
int * createCopyArray (int A[], int n) {
  int *R, i;
  R = (int *) malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    R[i] = A[i];
  }
  return R;
}

//Insertion sort
void insertionsort (int A[], int n) {
  int i, j, key;
  for (j=1; j<n; j++) {
    key = A[j];
    i = j - 1;
    while (i >= 0 && A[i] < key) {
        A[i+1] = A[i];
        i = i - 1;
    }
    A[i+1] = key;
  }
}

//Print array
void printArray (int A[], int n) {
  int i;
  for (i = 0; i<n; i++) {
    printf ("%d ", A[i]);
  }
  printf("\n");
}

//Sort and print an array
void sortArrayPrint (int A[], int n, char *name, void (*sortMethod)(int B[], int n)) {
  printf("array = ");
  printArray(A, n);
  printf("%s\n", name);
  sortMethod(A, n);
  printf("array = ");
  printArray(A, n);
}

//Measure running time
double measureRunningTime (int A[], int n, void (*sortMethod)(int B[], int n)) {
  clock_t t;
  double time_taken;
  t = clock();
  sortMethod(A, n);
  t = clock() - t;
  time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  return time_taken;
}