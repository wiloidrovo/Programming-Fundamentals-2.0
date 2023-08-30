#include <stdio.h>
#include <math.h>

// Structs
typedef struct point{
	int x;
	int y;
} Point;

typedef struct rect{
	Point pt1;
	Point pt2;
} Rect;

// Main Function
int main(void){
	Point a = {10, 50};
	Rect c = {{10, 20}, {30, 40}};
	Point *pp;
	Rect *pr;
	printf("Point a: (%d, %d)\n", a.x, a.y);
	printf("Rect c: ((%d, %d), (%d, %d))\n", c.pt1.x, c.pt1.y, c.pt2.x, c.pt2.y);
	pp = &a;
	pp->x += 10;
	pp->y += 20;
	pr = &c;
	pr->pt1.x += 10;
	pr->pt1.y += 10;
	printf("Point a: (%d, %d)\n", a.x, a.y);
	printf("Rect c: ((%d, %d), (%d, %d))\n", c.pt1.x, c.pt1.y, c.pt2.x, c.pt2.y);
return 0;
}