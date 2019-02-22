#include "../head.h"

int strLen(char *str)
{
	assert(str != NULL);

	int len = 0;
	while(*str++ != '\0')
		len++;

	return len;
}

int reverse1(char *str)
{
	char *start = str;
	char *end = str;
	char ch;

	while(*end++){};
	end--;
	end--;

	while(start < end){
		ch = *start;
		*start++ = *end;
		*end-- = ch;
	}
}

int reverse(char *str, char *dst)
{
	char *end = str;

	while(*end++){};
	end--;
	end--;

	
	if (str != NULL)
		while(*dst++ = *end--); //out of memory

	return 0;
}

/*func: find char in str
 * para:
 *  const char *src: string is found
 *  const char *chars: substr
 *return:
 * if char is found in string,return 0
 * else return -1
 * */
int find_str(const char *src,const char *chars, char *dst)
{
	assert(src != NULL);
	assert(chars != NULL);

	while(*chars != '\0'){
		while(*src != '\0'){
			if (*src == *chars){
				strcpy(dst, src);
				return 0;
			}
			src++;
		}
		chars++;
	}
	return -1;
}

char *del_substr(char *str, char const *substr)
{
	assert(str != NULL);
	assert(substr != NULL);

	int r = find_substr((const char *)str, substr);
	if (r >= 0){
		char *src = str;
		src += r;
		src--;

		for (const char *ch = substr; *ch != '\0'; ch++){
			*src = *(src+strlen(substr));
			src++;
		}
		char *tmp = src + strlen(substr);
		*src = '\0';
		strcat(src, tmp);
		return str;
	}else{
		printf("not find substr %s\n", substr);
		return NULL;
	}
}

/*func:find a substr in string
 *return:
 *	if find substr,return the start pos.
 *	else -1 is return
 * */
int find_substr(const char *src, const char *substr)
{
	if(src == NULL || substr == NULL)
		return -1;

	const char *sub = NULL;
	int start_pos = 0;
	
	while(*src != '\0'){
		sub = substr;
		if (*src == *sub){
			while(*src && *sub && (*src == *sub)){
				src++;
				sub++;
				start_pos++;
			}
			if (*sub == '\0')
				return start_pos - strlen(substr) + 1;
		}
		src++;
		start_pos++;
	}
	return -1;
} 

int string_cpy(const char *src, char *dst)
{
	if (src == NULL || dst == NULL)
		return -1;

	while((*dst++ = *src++) != '\0')
		;
	return 0;
}

int string_ncpy(const char *src, char *dst, size_t len)
{
	if (src == NULL || dst == NULL)
		return -1;

	while(len--){
		*dst++ = *src++;
	}
	return 0;
}
