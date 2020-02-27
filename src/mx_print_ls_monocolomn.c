#include "uls.h"

void mx_print_ls_monocolomn(char **data, t_args *args, char *path) {
    if (!isatty(1) || args->fl[8]) {
        int arr_size = mx_arr_size(data);

        for (int i = 0; i < arr_size; i++) {
        	mx_karetka_files(data[i]);
            mx_colored_name(args, data[i], path);
            mx_printchar('\n');
        }
    }
}
