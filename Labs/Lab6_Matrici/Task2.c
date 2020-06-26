#include <stdio.h>

int main () {
	int i, j, n, m, x;

	scanf("%d", &n);
	scanf("%d", &m);

	int v[n][m], h[n][m];

	for (i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}


		for (j = 0; j < n; j++){
			x = 0;
			for (i = n - 1; i >= 0; i--){
				h[j][x] = v[i][j];
				x++;
			}
		}

	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%d ", h[i][j] );
		}
		printf("\n");
	}
}
