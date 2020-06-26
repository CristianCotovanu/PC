#include <stdio.h>
#include <stdlib.h>
// Inversare vector prin pointeri
int main() {
	int v[100], aux, i, n, *p, *q;
	scanf("%d", &n);
	for(i = 0 ; i < n; i++)
		scanf("%d", (v + i));
	p = v;
	q = (v + n - 1);
	for(; p < q; p++, q--) {
		aux = *p;
		*p = *q;
		*q = aux;
	}

	for(i = 0 ; i < n; i++)
		printf("%d ", *(v + i));
		printf("\n");
	return 0;
}
