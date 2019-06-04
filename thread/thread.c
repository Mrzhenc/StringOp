#include "../include/apue.h"
#include <pthread.h>

struct foo{
	int a;
	int b;
	char s[512];
};

void printfoo(const char *s, const struct foo *fp);

void printids(const char *s)
{
	pid_t	pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
			(unsigned long)tid, (unsigned long)tid);
}

void *thr_fn1(void *arg)
{
	printids("new thread1:");
	return ((void *)1);
}

void *thr_fn2(void *arg)
{
	struct foo fp = {1, 2, "zhenchao"};
	printfoo("thread1:\n", &fp);
	printids("new thread1:");
	pthread_exit((void *)&fp); //使用return pthread_cancel函数不会被调用
}

void printfoo(const char *s, const struct foo *fp)
{
	printf("%s\n", s);
	printf("struct at 0x%lx\n", (unsigned long)fp);
	printf("foo->a = %d\n", fp->a);
	printf("foo->b = %d\n", fp->b);
	printf("foo->s = %s\n", fp->s);
}

int main()
{
	int err;
	void *tret;
	struct foo *fo;
	pthread_t ntid1, ntid2;
	err = pthread_create(&ntid1, NULL, thr_fn1, NULL);
	if (err != 0)
		printf("create thread1 error");

	err = pthread_create(&ntid2, NULL, thr_fn2, NULL);
	if (err != 0)
		printf("create thread2 error");

	err = pthread_join(ntid1, &tret);
	if (err != 0)
		printf("thread 1 join error");
	printf("thread 1 exit code %ld\n", (long)tret);
	
	err = pthread_join(ntid2, (void *)&fo);
	if (err != 0)
		printf("thread 2 join error");
	printfoo("main thread:\n", fo);
	sleep(1);
	exit(0);
}
