#include <stdio.h>

// Imprime la justificacion de la multiplicacion.

void procesar (int k, int x, int *sum){
	int i;
	
	for (i=1; i<k; i++){
		printf("%d +", x);
	}
	printf("%d = %d \n", x, x*k);
	*sum = *sum + x*k;
}

int main(void){
	int x, i, r=0;
	
	printf("Ingrese un numero porfavor: ");
	scanf("%d", &x);
	
	for (i=1; i<=10; i++){
		procesar(i, x, &r);
	}
	printf("sum = %d\n", r);
	return 0;
}