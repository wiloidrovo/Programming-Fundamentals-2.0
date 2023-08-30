// Example: Parameters by value and by reference
#include <stdio.h>
// Parameters by value
void f1 (int x) {
  x = x * 5;
  printf ("In f1 x is %d\n", x);
}

// Parameters by reference
void f2 (int *x) {
  *x = *x *5;
  printf ("In f2 x is %d\n", *x);
}

// Main function
int main (void) {
  int x = 10;
  printf ("By value\n");
  printf ("Before x = %d\n", x);
  f1(x);
  printf ("After x = %d\n", x);
  
  printf ("By reference\n");
  printf ("Before x = %d\n", x);
  f2(&x);
  printf ("After x = %d\n", x);
  
  return 0;
}