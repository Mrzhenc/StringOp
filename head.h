#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#define MAXLENGTH 1024

#define Debug(fmt, ...) do { \
	printf("%s-%s %s:%d:"fmt"", __DATE__, __TIME__, __FILE__, __LINE__, ##__VA_ARGS__); \
	}while(0)

/*return the string len*/
int strLen(char *);

/*reverse the string*/
int reverse1(char *);

/*find char in src, output the string after the char first occured*/
int find_str(const char *src, const char *c, char *dst);

/*delete substr in str*/
char *del_substr(char *str, char const *substr);

/*find substr in str, return the substr start pos in str*/
int find_substr(const char *str, const char *substr);

/*copy src to dst*/
int string_cpy(const char *src, char *dst);

/*copy len bytes to dst*/
int string_ncpy(const char *src, char *dst,  size_t len);

#endif
