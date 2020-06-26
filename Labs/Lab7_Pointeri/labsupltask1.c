#include <stdio.h>

void swap( int *a, int *b) {
	int aux = *a;
		*a = *b;
		*b = aux;
}

int main() {
	int a = 3, b = 5;
	swap(&a, &b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("%p\n", &a );
	printf("%p\n", &b );
}
