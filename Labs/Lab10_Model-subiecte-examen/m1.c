#include <stdio.h>

#define LIMIT 500
void func(int n) { 
	if(n < 0 || n > LIMIT) {
		return;
	}

	n = 2*n;
	printf("%d\n", n);
	func(n);
	printf("%d\n", n);
}

int main() {
	func(10);
	return 0;
}