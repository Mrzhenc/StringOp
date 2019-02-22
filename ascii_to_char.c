#include "head.h"

int main()
{
	for (int i = 0; i < 128; i++){
		//printf("%d=%c\n", i, (char*)i);
		putchar(i);
		putchar('\n');
	}

	printf("a = %d\n", (int)'a');
}
