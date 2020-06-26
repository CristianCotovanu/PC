#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, v[100], i;
	char output_filename[] = "outfile.bin";
	FILE *out;
	scanf("%d", &n);

	if((out = fopen(output_filename, "ab")) == NULL) {
		fprintf(stderr, "Can't open %s\n", output_filename);
		return -1;
	}

	// for(i = 0; i < n; i++) {
	// 	v[i] = rand();
	// 	printf("%d ", v[i]);
	// }

	//sau scriere in fisier caracter cu caracter
	// long*p;
	int a;
	for(i = 0; i < n; i++) {
		a = rand();
		// p = &a;
		fwrite(&a, sizeof(int), 1, out);
		printf("%p", &a);
		fputc(a, out);
		printf("%d ", a);
	}

	// fwrite(v, sizeof(int), n, out);
	fwrite("\n" ,sizeof(char), 1, out);
	fclose(out);

	return 0;
}