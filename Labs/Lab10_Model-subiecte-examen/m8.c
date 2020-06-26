#include <stdio.h>

int f(int *x) {
	return (*x)++;
}

int main() {
	int var = 3;
	printf("%d %d %d", var, f(&var), ++var);
	printf("\n");
	return 0;
}