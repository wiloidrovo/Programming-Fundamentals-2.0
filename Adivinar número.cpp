#include <stdio.h>

int main(void){
	int n=15, m;
	printf("Ingrese el numero a adivinar: ");
	scanf("%d", &m);
	while (m!=n){
		printf("Numero incorrecto, porfavor reintente: \n");
		scanf("%d", &m);
		if (m==0){
			printf("Uuuuu mi panita");
	break;
	}
	}
	if (m==n){
		printf("Adivino");
	}
return 0;
}