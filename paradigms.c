#include "head.h"

#define NAME(s) name##s
#define STRING(s) #s

#define CREAT(NAME, TYPE) \
	TYPE TYPE##NAME(void) \
	{					  \
		return 1;		  \
	}

//使用宏实现泛型
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

#define CREATE_ARRAY(ARRAY_NAME, ELE_TYPE, N_ELE) \
	static ELE_TYPE ARRAY_NAME[N_ELE]


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
	char *p = STRING(while);
	//printf("p=%s\n", p);

	CREAT_STACK(int, _int, 10)
	//printf("r=%d\n", is_full_int());

	CREAT(_int, int); //创建可变函数名
	//int a = int_int();
	//printf("a=%d\n", a);
	
	CREATE_ARRAY(array, int, 10);
	printf("buff size = %d\n", sizeof(array));

	CREATE_ARRAY(array1, char, 10);
	printf("buff size = %d\n", sizeof(array1));
	
	int a = 1;
	int b = 2;
	printf("before swap:a=%d b=%d\n", a, b);
	swap((void *)&a, (void *)&b, sizeof(int));
	printf("after swap:a=%d b=%d\n", a, b);

	char buff[6] = "hello";
	char buff1[6] = "world";
	printf("before swap:buff=%s buff1=%s\n", buff, buff1);
	swap((void *)buff, (void *)buff1, sizeof(buff));
	printf("after swap:buff=%s buff1=%s\n", buff, buff1);
	return 0;
}
