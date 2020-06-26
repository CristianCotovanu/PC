#include <stdio.h>

int main () {
	int C, i, j, n, m, max, k;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &C);

	int v[n][m];

	for (i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}

	max = v[0][0];

	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if( max < v[i][j])
				max = v[i][j];
		}
		v[i][C] = max;
		
		max = v[i][0];

	}

	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%d ", v[i][j] );
		}

		printf("\n");
	}
}