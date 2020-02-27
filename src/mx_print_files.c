#include "uls.h"

static void print_files_m(t_args *args, char **data, char *delim) {
    int count = 0;

    for(int i = 0; data[i] != NULL; i++) {
        if (mx_get_window_size(args) <= count + mx_strlen(data[i]) + 2) {
            mx_printstr("\n");
            count = 0;
        }
        mx_colored_name(args, data[i], NULL);
        if (data[i + 1])
            mx_printstr(delim);
        else
            mx_printstr("\n");
        count += (mx_strlen(data[i]) + 2);
    }
}

void mx_print_files(t_args *args) {
    if (args->files[0]) {
        if (args->fl[4] || args->fl[5] || args->fl[11])
            mx_print_file_ls(args);
        else if (args->fl[6])
            print_files_m(args, args->files, ", ");
        else
        if ((isatty(1) || args->fl[0]) && !args->fl[8]) {
            if (isatty(1) && args->fl[1])
                mx_print_multy_colomn_g(args->files, args, NULL);
            else
                mx_print_ls_multy_colomn(args->files, args, NULL);
        }
        else
            mx_print_ls_monocolomn(args->files, args, NULL);
        if (args->dirs[0])
            mx_printchar('\n');
    }
}

