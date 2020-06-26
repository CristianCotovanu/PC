#include <stdio.h>

#define N 100

void sum_left_neighbour( int v[N], int n) { 
	int i;

	for (i = n; i >= 1; i--) {

		v[i] = v[i] + v[i-1];

	}
}

void print_vector(int v[N], int n)
{
    int i;
 
    for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
    	}
    	printf("\n");
}
 
 void produs (int n, int v[100]) {
	int i, j, vector[100];

	for (i = 0; i < n; i++) {
		vector[i] = 1;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (j != i) 
				vector[i] = vector[i] * v[j];

	printf("%d", printare_vector(vector, n));



}


int main(void)
{
    int v[N] = {1, 2, 3, 4, 5}, k, n = 5, vector[100];
 
   	print_vector(v, 5);
    sum_left_neighbour(v, 5);
    print_vector(v, 5);
    produs(5, v);

    for(k = 0;k < n; k++)
    	printf("%d", vector[k]);
 
    scanf("%c", &input);

    int max = v[0], min = v[0], M, m, i;
    char input;

    for (i = 0; i < n; i++) {
    	if (M < v[i])
    		max = v[i];
    		M = i;

    	if (m > v[i])
    		min = v[i];
    		m = i;
    }

    if (input == 'q')
    	return 0;
     	else if (input == 'm') {
     		for (i = m; i < n; i++)
     			v[i] = v[i+1];
     	}	
     		else if (input == 'M') {
     			for(i = M; i < n; i++)
     				v[i] = v[i+1];
     		}
     			else if (input == 'p') {
     				for (i = 0; i < n; i++)
     					printf("%d", v[i]);
     			}
 
 return 0;   		
}


