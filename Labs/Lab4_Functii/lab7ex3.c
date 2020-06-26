#include <stdio.h>

int main() {
	
	int N, M, k = 0, x;

	scanf("%d%d", &N, &M);

	x = N ^ M;

	while (x > 0) {

		if(x % 2 == 1)
			k++;

		x = x / 2;
	}

	printf("%d\n", k);
	return 0;
}
