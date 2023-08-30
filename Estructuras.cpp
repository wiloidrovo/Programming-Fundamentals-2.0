#include <stdio.h>
#include <math.h>

// Structs
struct point{
	int x;
	int y;
};

struct rect{
	struct point pt1;
	struct point pt2;
};

// Prototipe
int area(struct rect c);

// Main function
int main(void){
	struct point a;
	struct point b = {320, 220};
	struct rect c;
	
	a.x = 100;
	a.y = 200;
	
	printf("Points:\n");
	printf("a = {%d, %d}\n", a.x, a.y);
	printf("b = {%d, %d}\n", b.x, b.y);
	c.pt1 = a;
	c.pt2 = b;
	printf("Rectangle:\n");
	printf("pt1 = {%d, %d}\n", c.pt1.x, c.pt1.y);
	printf("pt2 = {%d, %d}\n", c.pt2.x, c.pt2.y);
	printf("Area = %d", area(c));
return 0;
}

int area(struct rect c){
	int dist1, dist2, ar;
	dist1 = abs(c.pt2.x-c.pt1.x);
	dist2 = abs(c.pt2.y-c.pt1.y);
	ar = (dist1*dist2);
	return ar;
}

