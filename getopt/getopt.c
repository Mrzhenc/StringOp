#include "../head.h"
#include <stdarg.h>

// int getopt(int argc, char *const argv[], char *optstring);
// optsting eg a:b:c::d 一个冒号表示选项后必须有参数(可连在一起，也可空开)
// 两个表示可有可无 如果有的话，选项和参数之间不能有空格  没有:表示不带参数
// extern char *optarg 保存选项参数
// extern int optind 指向下一个选项下标
// extern int opterr 是否将错误输入到stderr，0表示不输出
// extern int optopt 表示不再optstring中的选项

int main(int argc, char **argv)
{
	int ch;
	while((ch = getopt(argc, argv, "ab:c:d:")) != -1){
		Debug("optind = %d\n", optind);
		switch(ch){
			case 'a':
				Debug("have -a option\n");
				break;
			case 'b':
				Debug("have -b option, arg is %s\n", optarg);
				break;
			case 'c':
				Debug("have -c option.arg is %s\n", optarg);
				break;
			case 'd':
				Debug("have -d option.arg is %s\n", optarg);
				break;
			case '?':
				Debug("Unknown option %c\n", (char)optopt);
				break;
			default:
				Debug("Unknown option %c\n", ch);
				break;
		}
	}
	return 0;
}

