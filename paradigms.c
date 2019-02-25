#include "head.h"

#define NAME(s) name##s
#define STRING(s) #s

#define CREAT(NAME, TYPE) \
	TYPE TYPE##NAME(void) \
	{					  \
		return 1;		  \
	}

#define CREAT_STACK(STACK_TYPE, NAME, SIZE) \
	static STACK_TYPE stack##NAME[SIZE];    \
	static int top_element##NAME = -1;      \
	STACK_TYPE is_full##NAME(void)          \
	{						                \
		if (top_element##NAME == -1)		\
			return 0;      					\
		else								\
			return 1;						\
	}


//泛型简单实现
void *swap(void *p1, void *p2 ,int nbyte)
{
	char tmp[nbyte];
	strcpy(tmp, (char*)p1);
	strcpy(((char *)p1), (char *)p2);
	strcpy((char *)p2, tmp);
}

void swap1(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int NAME(1);
	char *p = STRING(while);
	printf("p=%s\n", p);
	NAME(1) = 1;

	CREAT_STACK(int, _int, 10)
	printf("r=%d\n", is_full_int());


	CREAT(_int, int); //创建可变函数名
	int a = int_int();

	printf("a=%d\n", a);
	printf("%d\n", NAME(1));

	int c = 3;
	int b = 4;
	swap((void *)&c, (void *)&b, sizeof(int));
	printf("c = %d b = %d\n", c, b);

	char buff[6] = "hello";
	char buff1[6] = "world";
	swap((void *)buff, (void *)buff1, sizeof(buff));
	printf("%s:%s\n", buff, buff1);
	return 0;
}
