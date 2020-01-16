#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	if ((fd <= 0) || (buf_size <= 0) || (read(fd, NULL, 0) == -1))
		return -2;
	if (!delim || !lineptr)
		return -1;
	return 0;
}
