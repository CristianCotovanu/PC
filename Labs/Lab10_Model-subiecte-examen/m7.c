#include <stdio.h>
//waddup
int *foo(int *a, int *b, int n) {
	int c[100];
	int i;
	printf("%d\n", n);
	for( i = 0; i < n; i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}
int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {6, 7, 8, 9, 10};
	int *c = foo(a, b, sizeof(a));
	return 0;
}