#include <stdio.h>

void change(int *b, int n) {
	int i;
	for( i = 0; i < n; i++) {
		*(b + 2) = *(b + i);
	}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5};
	int i;
	change (a, 5);
	for( i = 0; i <= 4; i++)
		printf("%d ", a[i]);
	return 0;
}