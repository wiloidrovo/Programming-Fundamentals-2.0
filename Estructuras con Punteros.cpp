#include <stdio.h>

// Structs
struct point{
	int x;
	int y;
};

struct rect{
	struct point pt1;
	struct point pt2;
};

// Main Function
int main (void){
	struct point a = {10, 50};
	struct rect c = {{10, 20}, {30, 40}};
	struct point *pp;
}