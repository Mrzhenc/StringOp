#include "../include/apue.h"
#include <setjmp.h>

jmp_buf jmpbuffer;
void do_line(char *ptr);

int main()
{
	char buff[MAXLINE];

	if (setjmp(jmpbuffer) != 0)
		printf("setjmp error");
	while (fgets(buff, MAXLINE, stdin) != NULL)
		do_line(buff);
}

void do_line(char *ptr)
{
	printf("buff = %s\n", ptr);
	if (strncmp(ptr, "quit", 4) == 0)
	{
		longjmp(jmpbuffer, 1);
		printf("goto setjmp\n");
	}
}
