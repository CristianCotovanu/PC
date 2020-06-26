#include <stdio.h>

int main () {
	int v[100], i, x, y, n;
	scanf("%d%d%d", &x, &y, &n);


	for(i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	n = n + 1 ; 
	for(i = n; i >= x; i--)
		v[i+1] = v[i];

	v[x] = y;

	for(i = 0; i < n; i++)
		printf("%d ", v[i]);


	return 0;
}