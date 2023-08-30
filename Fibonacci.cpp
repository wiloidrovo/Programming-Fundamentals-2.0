#include <stdio.h>
#include <math.h>

// Recursive fibonacci
double fibonacci(int n){
	if (n==0 || n==1){
		return n;
	}
	else{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}

// Fibonacci with memoization
double fibonacci_memo(int n, double array[]){
	if (array[n] != -1){
		return array[n];
	}	
	if (n==0 || n==1){	
		array[n]=n;
    	return array[n];
	}
	else{
		array[n] = fibonacci_memo(n-2, array) + fibonacci_memo(n-1, array);
		return array[n];
	}
}

// Main function
int main(void){
	int i,n;
	printf("Ingrese el numero de elementos que desea: ");
	scanf("%d", &n);
	double x,array[n+1];
	/*
	x=pow(2, n);
	printf("%g\n", x);

	for (i=0; i<n; i++){
		printf("%g ", fibonacci(i));
	}
	*/
	for (i=0; i<n; i++){
		array[i] = -1;
	}
	for (i=0; i<n; i++){
		printf("%g ", fibonacci_memo(i, array));
	}
	return 0;
}