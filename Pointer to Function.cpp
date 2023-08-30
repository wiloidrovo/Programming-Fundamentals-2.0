#include <stdio.h>
#include <stdlib.h>

// Pointer to Function

void mesg(int num){
	printf("Mesg no. %d\n", num);
}
// Return a pointer to the sum
int* add(int x, int y){
	int *z = (int*)malloc(sizeof(int));
	*z = 10+x+y;
	return z;
}
// Main Function
int main(int argc, char* argv[]){
	int *t;
	void(*fpmsg)(int);  // Function pointer variable to point to the function "mesg"
	int* (*addfptr)(int, int);  // Function pointer variable to point to the function "add"
	addfptr = &add;  // Assignment using "adress of" operator
	fpmsg = mesg;  // Assignment using implicit method
	fpmsg(10);  // Invoking a function
	fpmsg(12);
	t = addfptr(5,7);
	printf("Add = %d\n", *t);
	free(t);
	return 0;
}