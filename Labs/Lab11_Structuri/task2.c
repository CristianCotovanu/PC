# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(){

	struct deque{
		int top;
		char elements[1000][31];
	}s;

	int i = 0, g, k, j;
	scanf("%d", &j);

	s.top = 0;
	s.elements[s.top][0] = ' ';

	for( g = 0; g < j ; g++){
		char s1[10], s2[] = "print";
		scanf("%s", s1);
		if( strcmp(s1,"print") == 0 )
			for( k = 0; k <= s.top ; k++)
				printf("%s ", s.elements[k]);
		if( strcmp(s1,"push") == 0 ){

			scanf("%s", s.elements[s.top+1]);
			s.top++;
			}
	if( strcmp(s1,"pop") == 0 ){
			s.top--;
			}
	}
	return 0;
}
