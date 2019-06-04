#include "../include/apue.h"
#include <sys/wait.h>

void pre_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal terminalion, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? "(core file generate)" : "");
#else
				"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal = %d\n", WSTOPSIG(status));
}

int main()
{
	pid_t pid;
	int status;

	if ( (pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		exit(7);

	if (wait(&status) != pid)
		printf("wait error\n");
	pre_exit(status);
	printf("status1");
	
	if ( (pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		abort();

	if (wait(&status) != pid)
		printf("wait error\n");
	pre_exit(status);
	printf("status1");
	
	if ( (pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		status /= 0;

	if (wait(&status) != pid)
		printf("wait error\n");
	pre_exit(status);
	printf("status1");
	
	exit(0);
}
