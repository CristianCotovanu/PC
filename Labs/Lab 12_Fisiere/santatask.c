#include <stdio.h>

void fsort (int M, int v[M]){
    int i, j, aux;
    for (i = 0; i < M - 1; i++){
        for (j = i; j < M; j++){
            if (v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    char input_filename[] = "in1.in";
    char input_filename2[] = "in2.in";
 
    FILE *in1 = fopen(input_filename, "rt");
    FILE *in2 = fopen(input_filename2, "rb");
 
    if (in1 == NULL && in2 == NULL) {
        fprintf(stderr, "Error: files can't be opened");
        return -1;
    }
 
    int n, m, i, j;

    fscanf(in1, "%d", &n);
    fscanf(in2, "%d", &m);
    int v[n + m + 1];
    for (i = 0; i < n; ++i) {
        fscanf(in1, "%d", &v[i]);
    }

    for (i = n; i < m + n; ++i){
        fscanf(in2, "%d", &v[i]);
    }
 
    fclose(in1);
    fclose(in2);
 
    
    char output_filename[] = "out.out";
    FILE *out = fopen(output_filename, "wb");
 
    if (out == NULL) {
        fprintf(stderr, "Error: can't open file %s", output_filename);
        return -1;
    }
    fsort(n + m, v);
     for (i = 0; i < n + m; ++i) {
        fprintf(out, "%d ", v[i]);
    }
    fprintf(out, "\n");
    fclose(out);
 
    return 0;
}