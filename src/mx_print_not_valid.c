#include "uls.h"

void mx_print_not_valid(char *data) {
	DIR *dir = opendir(data);

	if (errno == 0) {
		closedir(dir);
		return;
	}
	write(2, "uls: ", 5);
	perror(data);
	errno = 0;
}
