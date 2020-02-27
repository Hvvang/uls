#include "uls.h"

t_args *mx_sort_args(int argc, char **argv) {
	t_args *args = (t_args *)malloc(sizeof (t_args));
	int index = 1;

	args->error = 0;
	mx_get_flags(args, &index, argc, argv);
	mx_args_to_struct(index, argc, argv, args);
	args->files = mx_sort_data(args, args->files);
	args->dirs = mx_sort_data(args, args->dirs);
	args->not_valid = mx_sort_data(args, args->not_valid);
	for (int i = 0; args->not_valid[i]; i++) {
		mx_print_not_valid(args->not_valid[i]);
		args->error = 1;
	}
	return args;
}
