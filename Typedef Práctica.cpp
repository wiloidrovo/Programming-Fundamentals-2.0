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

// Prototipe
double area(Coor d);
//int scan(char word);
void scan(Point a, Point b, Point c);

// Main Function
int main(void){
	Point a, b, c;
	Coor d = {a, b, c};
	//char word;
	scan(a, b, c);
	//printf("Ingrese la primera coordenada: \n");
	//scanf("%d, %d", &a.x, &a.y);
	//printf("Ingrese la segunda coordenada: \n");
	//scanf("%d, %d", &b.x, &b.y);
	//printf("Ingrese la tercera coordenada: \n");
	//scanf("%d, %d", &c.x, &c.y);
	//Coor d = {a, b, c};
	//printf("Coor d: ((%d, %d), (%d, %d), (%d, %d))\n", a.x, a.y, b.x, b.y, c.x, c.y);
	//printf("Area = %f\n", area(d));
	//scan(word);
return 0;
}

// Area Function
double area(Coor d){
	double la, lb, lc, sp, ar;
	//potencia = pow(numero, potencia);
	la = sqrt(pow((d.pt2.x-d.pt1.x),2)+pow((d.pt2.y-d.pt1.y),2));
	lb = sqrt(pow((d.pt3.x-d.pt2.x),2)+pow((d.pt3.y-d.pt2.y),2));
	lc = sqrt(pow((d.pt3.x-d.pt1.x),2)+pow((d.pt3.y-d.pt1.y),2));
	printf("la = %f\n", la);
	printf("lb = %f\n", lb);
	printf("lc = %f\n", lc);
	sp = (la + lb + lc)/2;
	printf("sp = %f\n", sp);
	ar = sqrt(sp*(sp-la)*(sp-lb)*(sp-lc));
	return ar;
}

// Scanf Function 1
//int scan(char word){
//	do{
//		printf("Words %c\n", word);
//	} while(word <= 'c');
//return 0;
//}

// Scanf Function 2
//int scan(char word){
//	for(word = 'a'; word <= 'c'; word++){
//		printf("Words %c\n", word);
//		printf("Ingrese la primera coordenada: \n");
//		scanf("%d, %d", &word.x, &word.y);		
//	}
//return 0;
//}

// Scanf Function 3
void scan(Point a, Point b, Point c){
	printf("Ingrese la primera coordenada: \n");
	scanf("%d, %d", &a.x, &a.y);
	printf("Ingrese la segunda coordenada: \n");
	scanf("%d, %d", &b.x, &b.y);
	printf("Ingrese la tercera coordenada: \n");
	scanf("%d, %d", &c.x, &c.y);
	Coor d = {a, b, c};
	printf("Coor d: ((%d, %d), (%d, %d), (%d, %d))\n", a.x, a.y, b.x, b.y, c.x, c.y);
	printf("Area = %f\n", area(d));
}