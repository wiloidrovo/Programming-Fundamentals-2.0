#include <stdio.h>

// Compute the Sum

int example1(int n){
	int i, s=0, t;
	for (i=1; i<=n; i++){
		t=(i*i);
		s+=t;
		if (i==n){
			printf("%d^2", i);
		}
		else
			printf("%d^2 +", i);
	}
	return s;
}

int main(void){

	int n, r;
	
	printf("Ingrese un numero: ");
	scanf("%d", &n);
	r=example1(n);
	printf("\n el resultado es: %d", r);
return 0;
}