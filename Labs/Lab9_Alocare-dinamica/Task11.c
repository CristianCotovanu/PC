#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min( int a, int b) {
	if (a < b)
		return a;
	else 
		return b;
}

 int *my_realloc(int *initial, int old_size, int new_size) {
 	int *aux = malloc(new_size * sizeof(int));
 	if(aux) {
 		memcpy(aux, initial, min(new_size,old_size) * sizeof(int));
 		free(initial);
 		return aux;
 	}
 	else
 		return NULL;
 }
 void afisare(int v[], int n) {
 	int i;
 	for ( i = 0; i < n; i++) {
 		printf("%d ", v[i]);
 	}
 }
 int main()
 {	
 	int n = 0, m = 0, i;
 	int *v = (int*)malloc(n * sizeof(int));
 	// Old size
 	scanf("%d", &n);
 	//Citire vector
 	for(i = 0 ;i < n; i++)
 		scanf("%d", &v[i]);
 	// New size
 	scanf("%d", &m);

 	v = my_realloc(v, n, m);
 	afisare(v, m);
 	return 0;
 }
