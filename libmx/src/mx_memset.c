#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	size_t i;
	unsigned char* temp = b;

	for (i = 0; i < len; i++)
		*(temp++) = c;
	return b;
}
