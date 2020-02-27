#include "uls.h"

int main(int argc, char **argv) {
	t_args *args = mx_sort_args(argc, argv);
	int error = 0;

	if (args->files[0])
        mx_print_files(args);
	mx_open_dirs(args);
	error = args->error;
	mx_del_args_struct(args, NOT_VALID);
	exit(error);
}
