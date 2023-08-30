#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main Function
int main()
{
    char number[10];
    char c;
    int i, j, digit, l, s, p;
    printf("Enter a number in octal: ");
    scanf ("%s", number);
    l = strlen(number);
    printf ("The number is %s with %d characters\n", number, l);
    printf ("#) char = ascii -> int\n");
    s = 0;
    for (i = 0; i < l; i++) {
        c = number[i];
        digit = c - 48;
        printf ("%d) %c = %d -> %d * 8^%d ",
                i+1, c, c, digit, i);
        p = 1;
        for (j = 0; j<i; j++) {
            p = p * 8;
        }
        printf (" = %d\n", digit*p);
        s += digit*p;
    }
    printf ("Octal %s -> decimal %d\n", number, s);
    return 0;
}