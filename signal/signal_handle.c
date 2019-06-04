#include "../include/apue.h"
#include <sys/wait.h>

static void sig_int(int);
static void sig_usr(int);
typedef void Sigfunc(int);

int main()
{
	char buf[MAXLINE];

	//if (signal(SIGINT, sig_int) == SIG_ERR)
		//perror("signal error");
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2");
	
	while(1)
	{
		pause();
	}
	return 0;
}

static void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("catch sigusr1\n");
	else if (signo == SIGUSR2)
		printf("catch sigusr2\n");
	else
		printf("received, signal %d\n", signo);
}

static void sig_int(int signo)
{
	printf("signal recv\n%% ");
}
