#include "../head.h"

int main(void)
{
	char buff[128] = "helloworld";
	//int len = strLen(buff);
	//int pos = find_substr(buff, "wor");
	char *p = del_substr(buff, "hello");
	Debug("p=%s\n", p);
	//printf("pos=%d\n", pos);
	//printf("len=%d\n", len);
	return 0;
}
