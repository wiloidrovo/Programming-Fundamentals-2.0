#include<stdio.h>
#include<math.h>
int main (void){
	int a=15, i, b, umbrall=5, count=0;
	while(count==0){
		printf("Porfavor adivine e ingrese un numero entero:\n");
		scanf("%d",&b);
		if(a==b){
			printf("Ya estafff mi panita");
			break;
		}
		else{
			printf("Incorrecto\n");
		}
// Comparamos si el numero ingresado es mayor o menor al numero guardado
		if(a<b){
			if(b-a>umbrall){
				if(b-a>2*umbrall){
					printf("helado \n");
				}
				else{
					for(i=0;i<((b-a)-5);i++){
						printf("frio \n");
					}
				}
			}
			if(b-a<=umbrall){
				for(i=0;i<(b-a);i++){
					printf("caliente \n");
				}
			}
		}
		//if(b<a)
		else{
			if(a-b<=umbrall){
				for(i=0;i<(a-b);i++){
					printf("caliente \n");
				}
			}
			if(a-b>umbrall){
				if(a-b>2*umbrall){
					printf("helado \n");
				}
				else{
					for(i=0;i<((a-b)-5);i++){
						printf("frio \n");
					}
				}
			}
		}
	}
}