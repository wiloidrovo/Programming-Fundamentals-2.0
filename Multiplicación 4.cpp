#include <stdio.h>
#include <stdlib.h>

// Explanation
void explanation (int x, int k, int *r) {
    int i;
    printf (" because ");
    for (i=1; i<k; i++)
        printf ("%d + ", x);
    printf ("%d = %d\n", x, x*k);
    *r = *r + x*k;
}

// Main Function
int main(void) {
    int x;
    int i;
    int r = 0;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (i=4; i<=20; i=i+4) {
        printf ("%d * %d = %d ", x, i, x * i);
        explanation (x, i, &r);
    }
    printf ("Sum = %d \n", r);
    return 0;
}