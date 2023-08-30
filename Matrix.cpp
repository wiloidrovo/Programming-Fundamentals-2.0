#include <stdio.h>
#include <string.h>

#define MAXCHAR 250
#define MAXNAMES 50

// Print names from a matrix of chars
void printNamesMatrix (char arrayNames[MAXNAMES][MAXCHAR], int n);

// Read names in a matrix of chars
void readNamesMatrix (char arrayNames[MAXNAMES][MAXCHAR], int n);

int main(void){
	int n;
	char M[MAXNAMES][MAXCHAR];
	scanf ("%d", &n);
	readNamesMatrix (M, n);
	printNamesMatrix (M, n);
return 0;
}