    #include <stdio.h>
     
    #define N 100
     
     
    void transpose_matrix(int m[N][N], int n)
    {
    	int i, j, tmp;
     
    	for (i = 0; i < n; i++) {
    		for (j = i + 1; j < n; j++) {
    			tmp = m[i][j];
    			m[i][j] = m[j][i];
    			m[j][i] = tmp;
    		}
    	}
    }
     
     
    void print_matrix(int m[N][N], int n)
    {
    	int i, j;
     
    	for (i = 0; i < n; i++) {
    		for (j = 0; j < n; j++) {
    			printf("%d ", m[i][j]);
    		}
    		printf("\n");
    	}
    	printf("\n");
    }
     
     
    int main(void)
    {
    	int i, j, n = 3, diagS = 0;
     
    	int v[N][N] = {
    		{1, 2, 3},
    		{4, 5, 6},
    		{7, 8, 9}
    	};

            }

        /* printf("Introduceti numarul pentru ordinul matricei: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                printf("Introduceti elementul matricei: ");
                scanf("%d", &v[i][j]);
                                        */

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
               
                if( i < j )
                    diagS = diagS + v[i][j];

            }

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {

                if( j > (n - i + 1))
                    printf("%d", v[i][j]);}

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {

                if( j < (n - i + 1))
                    v[i][j] = 0;      
}            

    	print_matrix(v, n);
    	transpose_matrix(v, n);
    	print_matrix(v, n);
        printf("%d", diagS);
    	return 0;
    }

