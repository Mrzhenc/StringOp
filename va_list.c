#include "head.h"
#include <stdarg.h>

float ava(int num, ...)
{
	va_list vl;
	int n = 0;
	va_start(vl, num);
	printf("num=%d\n", num);

	for (int i = 0; i < num; i++){
		n += va_arg(vl, int);
		printf("n=%d\n", n);
	}
	va_end(vl);
	return n/num;
}

int main()
{
	float r = ava(4, 2, 3, 4, 5);
	printf("r=%2f\n", r);
	return 0;
}
