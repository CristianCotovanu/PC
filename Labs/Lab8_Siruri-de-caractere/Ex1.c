#include <stdio.h>

int longestIncreasingSubstring (int v[], int n) {
	int i, count = 0, max = 0;
	
	if(n = 1)
		return 1;

	for( i = 0; i < n; i++) {
		if(count > max)
			max = count;
		if(v[i] > v[i+1])
			count = 0;
		else 
			count++;
	}
	return max;
}


Enunt

Cel mai mare substring crescator intr-un vector