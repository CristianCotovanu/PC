#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

 int * my_realloc (int *initial, int old_size, int new_size) {
 	int  *memory = malloc(new_size * sizeof(int))
 	if (memory) {
 		memcpy(memory, initial, min(new_size, old_size) * sizeof(int));
 		free(initial);
 	} else return NULL ;
 }

 int main () {
 	int i, n = 0, m = 0;
 	int *v = (int *)malloc(n*sizeof(int));
 	scanf("%d", &n);
 	for(i = 0 ;i < n; i++)
 		scanf("%d", v[i]);
 	scanf("%d", &m);
 	v = my_realloc(v, n, m);
 	for(i = 0; i < m; i++) {
 		printf("%d", *(v+i));
 		if(i < m - 1)
 			printf(" ");
 	}
 	printf("\n");
 	return 0;
 }
