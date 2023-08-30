#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Structs
typedef struct point{
	int x, y;
} Point;

typedef struct coor{
	Point pt1, pt2, pt3;
} Coor;

// Prototipes
double area(Coor d);
void scan(Point a, Point b, Point c);

// Main Function
int main(void){
	Point A, B, C;
	Coor d = {A, B, C};
	scan(A, B, C);
return 0;
}

// Area Function
double area(Coor d){
	double la, lb, lc, Sp, ar;
	la = sqrt(pow((d.pt2.x-d.pt1.x),2)+pow((d.pt2.y-d.pt1.y),2));
	lb = sqrt(pow((d.pt3.x-d.pt2.x),2)+pow((d.pt3.y-d.pt2.y),2));
	lc = sqrt(pow((d.pt3.x-d.pt1.x),2)+pow((d.pt3.y-d.pt1.y),2));
	printf("la = %f\n", la);
	printf("lb = %f\n", lb);
	printf("lc = %f\n", lc);
	Sp = (la + lb + lc)/2;
	printf("Sp = %f\n", Sp);
	ar = sqrt(Sp*(Sp-la)*(Sp-lb)*(Sp-lc));
	return ar;
}

// Scanf Function
void scan(Point a, Point b, Point c){
	printf("Ingrese la primera coordenada: \n");
	scanf("%d, %d", &a.x, &a.y);
	printf("Ingrese la segunda coordenada: \n");
	scanf("%d, %d", &b.x, &b.y);
	printf("Ingrese la tercera coordenada: \n");
	scanf("%d, %d", &c.x, &c.y);
	Coor d = {a, b, c};
	printf("Coor d: {(%d, %d), (%d, %d), (%d, %d)}\n", a.x, a.y, b.x, b.y, c.x, c.y);
	printf("Area = %0.02f\n", area(d));
}