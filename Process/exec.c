#include "../include/apue.h"
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL};
int main()
{
	pid_t pid;
	if ( (pid = fork()) < 0){
		printf("fork error\n");
	} else if (pid == 0){
		if (execle("/root/workspace/fork/echoall", "echoall", "myarg1", "My arg2", (char *)0, env_init) < 0){
			printf("execle error\n");
		}
	}

	if (waitpid(pid, NULL, 0) < 0)
		printf("waitpid error\n");
	
	exit(0);
}
