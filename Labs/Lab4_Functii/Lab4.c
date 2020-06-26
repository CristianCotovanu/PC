#include <stdio.h>

int suma(long nr) {
    int sum = 0;

    while(nr != 0) {

        sum = sum + nr % 10;

        nr = nr / 10;
    }
    return sum;
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", suma(n));

    return 0;
}