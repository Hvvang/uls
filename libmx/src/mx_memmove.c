#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	char *temp = (char *)dst;
	char *str = (char *)src;
	char *buf = mx_strnew(len);
	unsigned i;

	for (i = 0; i < len; i++)
		buf[i] = str[i];
	for (i = 0; i < len; i++)
		temp[i] = buf[i];
	return temp;
}
