#include "../head.h"

int b = 1; //作用于整个文件，如果外部需要访问 extern int b;
static int c = 1;//作用于整个文件，外部不可访问
extern int num; //外部文件导入变量
extern int add(int a, int b);//外部文件导入函数

void func()
{
	//存放在静态数据区，并且只初始化一次
	static int a = 1;
	a++;
	printf("a = %d\n", a);
}

int main()
{
	printf("n = %d\n", num);
	printf("add = %d\n", add(1, 2));
	func();// a = 2
	func();// a = 3
	return 0;
}
