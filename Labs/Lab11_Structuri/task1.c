#include <stdio.h>
#include <math.h>

typedef struct numar{
	int Im,Re;
} Numar;

int main() {
	Numar nr[100], aux;
	int module[100], i, j, rad1, rad2, n;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &nr[i].Re);
		scanf("%d", &nr[i].Im);
	}

	for(i = 0; i < n - 1; i++) 
		for(j = i + 1; j < n; j++) {
			rad1 = sqrt(pow(nr[i].Im, 2) * pow(nr[i].Re, 2));
			rad2 = sqrt(pow(nr[j].Im, 2) * pow(nr[j].Re, 2));
			if( rad1 > rad2 ) {
				aux = nr[i];
				nr[i] = nr[j];
				nr[j] = aux;
			}
		}

	for(i = 0; i < n; i++) 
		printf("(%d,%d)", nr[i].Im, nr[i].Re);

		return 0;

}