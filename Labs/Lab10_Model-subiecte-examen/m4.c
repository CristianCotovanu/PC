#include <stdio.h>

void foo(int i, int j) {
	if(j > 0) {
		foo(i, j - 1 );
	}
	printf("%d * %d = %d\n", i, j, i*j );
}
int main()
{
	foo(9, 9);
	return 0;
}