#include <stdio.h>
#include <stdlib.h>

// Print data
void printData (float *data, int n);
// Read data from keyboard
float * readData (int n);
// Mean of the data
float meanData (float *data, int n);
// Variance of the data
float varData (float *data, int n);
// Minimo
float min (float *data, int n);
//Maximo
float max (float *data, int n);
//Utilidad
float utilidad (float *data, int n, int *compra, int *venta);

// Main function
int main (void) {
  float * data, prom, var;
  int n, c, v;
  scanf("%d", &n);
  data = readData (n);
  printData (data, n);
  prom=meanData (data, n);
  //printf("El promedio  es %f", prom);
  var=varData (data, n);
  //printf("\n La varianza  es %f", var);
  //printf("\n El minimo es %f", min (data, n));
  //printf("\n El maximo es %f", max (data, n));
  printf("\n La maxima utilidad es %f\n", utilidad (data, n, &c, &v));
  printf("\n Compra = %d Venta = %d \n", c, v);
  free (data);
  return 0;
}

// Print data
// https://cplusplus.com/reference/cstdio/printf/
void printData (float *data, int n) {
  int i, c = 0;
  printf ("Data: \n");
  for (i = 0; i < n; i++) {
    printf ("%8.02f", data[i]);
    c++;
    if (c == 5) {
      printf ("\n");
      c = 0;
    }    
  }
  printf ("\n");
}

// Read data from keyboard
float * readData (int n) {
  float * ptrData;
  int i;
  ptrData = (float *) malloc (sizeof(float) * n);
  for (i = 0; i < n; i++) {
    scanf ("%f", &ptrData[i]);
  }
  return ptrData;
}

// Mean of the data
float meanData (float *data, int n){
	float prom, suma=0;
	int i;
	for (i=0; i<n; i++){
		suma+= data[i];
	}
	prom=(suma/n);
	//printf("el promedio  es %f", prom);
	return prom;
}

// Variance of the data
float varData (float *data, int n){
	int i;
	float var, suma2=0;
	float promedio = meanData (data, n);
	for (i=0; i<n; i++){
		suma2 += (data[i]-promedio)*(data[i]-promedio);
	}
	var = (suma2/n);
	return var;
}

// Minimo
float min (float *data, int n){
	int i;
	float minimo = data[0];
	for (i=1; i<n; i++){
		if (data[i]<minimo){
			minimo = data[i];
		}
	}
	return minimo;
}

// Maximo
float max (float *data, int n){
	int i;
	float maximo = data[0];
	for (i=1; i<n; i++){
		if (data[i]>maximo){
			maximo = data[i];
		}
	}
	return maximo;
}

float utilidad (float *data, int n, int *compra, int *venta){
	int i, j;
	float uti = 0, m = -1000000;
	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
			uti = data[j] - data[i];
			if (uti>m){
				m=uti;
				*compra = i;
				*venta = j;
			}
			//printf("\n U(i=%d, j=%d)= %0.02f \t", i, j, uti);
		}
		//printf("\n");
	}
	return m;
}