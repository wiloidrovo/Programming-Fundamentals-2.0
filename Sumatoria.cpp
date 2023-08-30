#include <stdio.h>

int main(void){

	int n, i, r=0;
	
	printf("Ingrese un numero: ");
	scanf("%d", &n);
	
	for (i=1; i<=n; i++){
		r+=i;
	}
	printf("el resultado es: %d", r);
	
return 0;
}