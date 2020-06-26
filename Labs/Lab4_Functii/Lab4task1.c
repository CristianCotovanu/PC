#include <stdio.h>

int minim(int n) {

	if (n == 0)
		return 9;

	if ( n % 10 < minim(n / 10))
		return n % 10;

}


int main()
{	
	int nr;

	scanf("%d", &nr);

	printf("%d\n", minim(nr));

	return 0;
}