#include <stdio.h>

int main(void){
	int n, i, j;
	
	printf("Ingrese un numero porfavor: ");
	scanf("%d", &n);
	
	for (i=1; i<=10; i++){
		printf("%d x %d = %d \n", n, i, n*i);
	}
	return 0;
}