#include "uls.h"

static char *r_find(char *data) {
	int lenth = mx_strlen(data);

	while (data[lenth - 1] != '/')
		lenth--;
	return &data[lenth];
}

static void stat_checking(int mult, char *data, struct stat *buf) {
	int lstat_h = lstat(data, buf);
	char *parse = r_find(data);

	if (lstat_h) {
		write(2, "uls: ", 5);
		perror(data);
		errno = 0;
	}
	else {
		if (mult) {
			mx_printstr(data);
			mx_printstr(":\n");
		}
		parse = mx_strjoin("uls: ", parse);
		perror(parse);
		mx_strdel(&parse);
		errno = 0;
	}
}

int mx_check_on_access(int mult, char *data,t_args *args) {
	DIR *dir = NULL;
	struct stat buf;

	errno = 0;
	dir = opendir(data);
	if (errno) {
		stat_checking(mult, data, &buf);
		args->error = 1;
		if (dir)
			closedir(dir);
		return -1;
	}
	if (dir)
		closedir(dir);
	return 0;
}
