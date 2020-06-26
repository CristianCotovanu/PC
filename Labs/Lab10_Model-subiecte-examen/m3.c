#include <stdio.h>
#include <string.h>

//Se schimba adresele
void swap( char *t1, char *t2 ) {//cum apelez in main **char 
	char *t;
	t = t1;
	t1 = t2;
	t2 = t;
}

int main() {
	char *s[2] = { "Hello", "World"};
	swap(s[0], s[1]);
	printf("%s %s\n", s[0], s[1] );

	return 0;
}