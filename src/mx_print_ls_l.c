#include "uls.h"

void mx_print_ls_l(t_args *args, t_dirs *dirs) {
	if (!mx_check_on_access(0, dirs->dir, args)) {
		mx_print_dirs_ls(dirs, args);
	}
}
