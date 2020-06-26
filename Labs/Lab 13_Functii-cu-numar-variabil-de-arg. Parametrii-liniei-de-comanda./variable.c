#include <stdio.h>
#include <stdarg.h>

void maximum(int num, ...) {
	int i = 0;
	int arg1, max1;
	double arg2, max, max2;
	va_list args;

	va_start(args, num);

	max = va_arg(args, double);

	for(i = 1; i < num; i++) {
		arg2 = va_arg(args, double);
		arg1 = va_arg(args, int);
		if(max1 < arg1) {
			max1 = arg1;
		}
		if(max2 < arg2) {
			max2 = arg2;
		}
	}

	if (max1 > max2) {
		max = max1;
	} else {
		max = max2;
	}
	va_end(args);
	printf("Maximum value is %f\n", max);
}

int main() {

	int count = 7;
	maximum(count, 5, 21, 8224, 90021, 99, 20);

	return 0;
}