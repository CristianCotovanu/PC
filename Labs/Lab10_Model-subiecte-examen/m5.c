#include <stdio.h>
#include <string.h>
//Eliminarea a 2 litere alaturare identice
int main() {
	char s[9] = "abbacddc";
	int i = 0;
	while (i < strlen(s) - 1) {
		if (s[i] == s[i+1]){
			strcpy( s + i, s + i + 2);
			if(i > 0) {
				i = i - 1;
			}
		}
		else {
			i = i + 1;
		}
	}
	printf("%s\n", s);
	return 0;
}