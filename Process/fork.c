#include "../include/apue.h"

int globval = 6;
char buf[] = "a write to stdout\n";

int main()
{
	int var;
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		printf("wirte stdout failed\n");

	printf("before fork\n"); //如果输出到标准输出，则子进程不打印该行,换行冲洗缓冲区

	if ( (pid = fork())< 0){
		printf("fork error\n");
	}else if (pid == 0){
		var++;
		globval++;
	} else{
		sleep(2);
		printf("parent process exit\n");
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globval, var);
	exit(0);
}
