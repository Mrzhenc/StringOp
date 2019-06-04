#include "../include/apue.h"

int globval = 6;
char buf[] = "a write to stdout\n";

int main()
{
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n"); //如果输出到标准输出，则子进程不打印该行,换行冲洗缓冲区

	// vfork 子进程在父进程的地址空间运行
	// 保证子进程退出之后，父进程才继续运行
	if ( (pid = vfork())< 0){
		printf("vfork error\n");
	}else if (pid == 0){
		var++;
		globval++;
		_exit(0); // _exit() 不执行缓冲区的冲洗操作
	} else{
		printf("parent process exit\n");
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globval, var);
	exit(0);
}
