#include <stdio.h>

void f1 (int a, int b){
	a = a + b;
	printf("f1 ->a = %d\n", a);
}

void f2 (int *a, int b){
	*a = *a + b;
	printf("f1 ->a = %d\n", *a);
}

int main(void){
	int a, b;
	a=5, b=6;
	f2(&a, b);
	printf("a = %d y b = %d", a, b);
	return 0;
}