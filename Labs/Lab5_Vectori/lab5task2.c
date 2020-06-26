#include <stdio.h>
int main () {
	int v[100],x[100],n ,i;

	for(i = 0; i < n; i++){
		x[i] = 0;
		}

	scanf("%d", &n);
	for(i = 0; i < n; i++) {

		scanf("%d", &v[i]);
		
		x[v[i]] ++;

	}
	for(i = 0; i < 100; i++){
		if(x[i] != 0)
		{
			printf("element %d ",i);
			printf("apare de %d", x[i]);
			printf("ori \n");
		}
	}

return 0;}
