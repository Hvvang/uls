#include "uls.h"

void mx_del_args_struct(t_args *args, int item) {
    switch (item) {
        case NOT_VALID:
            mx_del_str_arr(args->not_valid);
        case DIRS:
            mx_del_str_arr(args->dirs);
        case FILES:
            mx_del_str_arr(args->files);
        case FLAGS:
            mx_strdel(&args->flags);
        default:
            free(args);
            args = NULL;
    }
}
