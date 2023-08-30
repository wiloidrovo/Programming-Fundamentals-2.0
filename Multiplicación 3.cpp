#include <stdio.h>

int main(void){
	int n, i, j;
	
	printf("Ingrese un numero porfavor: ");
	scanf("%d", &n);
	
	for (i=10; i>=1; i--){
		for (j=2; j<=i; j++){
			printf("%d + ", n);
		}
		printf("%d = %d\n", n, n*i);
	}
	return 0;
}