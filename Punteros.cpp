#include <stdio.h>

// Prototipes
void swap1(int x, int y);
void swap2(int *px, int *py);

// Pointer basics
int main(void){
	int x, y;
	int a=8, b=10;
	int *ip; // Pointer to integer
	char *cp;
	
	printf("Size (int) = %d, size (int *) = %d\n", (int)sizeof(x), (int)sizeof(ip));
	printf("Size (char) = %d, size (char *) = %d\n", (int)sizeof(a), (int)sizeof(cp));
	
	x = 15; y = 15;
	ip = &x;
	printf("ip = %p\n", ip);
	*ip = *ip + 1;
	ip = &y;
	printf("ip = %p\n", ip);
	(*ip)--;
	printf("x = %d y = %d\n", x, y);
	
	printf("&ip = %p\n", &ip);
	
	ip = &y;
	*ip = *ip-4;
	printf("ip2 = %d\n", *ip);
	swap1(a, b);
	printf("a = %d, b = %d\n", a, b);
	swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);
return 0;
}

void swap1(int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swap2(int *px, int *py){
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}


