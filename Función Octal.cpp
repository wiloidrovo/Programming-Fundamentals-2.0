#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// First Function
void potencia(int exponente, int digit, int *s){
	int p, j;
	p = 1;
	for (j = 0; j<exponente; j++){
        p = p * 8;
    }
    printf (" = %d\n", digit*p);
    *s += digit*p;
}
// Second Function
int potencia2(int base, int exponente){
	int p, j;
	p = 1;
	for (j = 0; j<exponente; j++){
        p = p * base;
	}
	return p;
}


// Main Function
int main()
{
    char number[10];
    char c;
    int i, digit, l, s, exponente, m;
    printf("Enter a number in octal: ");
    scanf ("%s", number);
    l = strlen(number);
    printf ("The number is %s with %d characters\n", number, l);
    printf ("#) char = ascii -> int\n");
    s = 0;
    for (i = 0; i < l; i++) {
        c = number[i];
        digit = c - 48;
        exponente = l-i-1;
        printf ("%d) %c = %d -> %d * 8^%d ",
                i+1, c, c, digit, l-i);
        //potencia(l-i-1, &s, digit);
        m = digit*potencia2(8, exponente);
        s+=m;
        printf (" = %d\n", m);
    }
    printf ("Octal %s -> decimal %d\n", number, s);
    return 0;
}