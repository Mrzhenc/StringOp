#include "../include/apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main()
{
	if ((atexit(my_exit1)) != 0)
		printf("can not register exit1\n");

	if ((atexit(my_exit2)) != 0)
		printf("can not register exit2\n");	
	
	if ((atexit(my_exit1)) != 0)
		printf("can not register exit1\n");

	printf("end process\n");

	printf("env:\n%s\n", getenv("HOME"));// get env var
	return 0;
}

static void my_exit1(void)
{
	printf("exit1 is called\n");
}

static void my_exit2(void)
{
	printf("exit2 is called\n");
}
