#include "uls.h"

void mx_print_dirs_m(t_args *args, t_dirs *dirs, char *delim) {
	int count = 0;

	if (!mx_check_on_access(0, dirs->dir, args)) {
		char **data = mx_get_data_from_struct(dirs);

		for(int i = 0; data[i] != NULL; i++) {
			if (mx_get_window_size(args) <= count + mx_strlen(data[i]) + 2) {
				mx_printstr("\n");
				count = 0;
			}
			mx_colored_name(args, data[i], dirs->dir);
			if (data[i + 1])
				mx_printstr(delim);
			else
				mx_printstr("\n");
			count += (mx_strlen(data[i]) + 2);
		}
		mx_del_str_arr(data);
	}
}
