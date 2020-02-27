#include "uls.h"

void mx_print(t_args *args, t_dirs *dirs,
              void (*print)(char **, t_args *, char *dir)) {
    if (dirs) {
        char **data = NULL;

        if (!mx_check_on_access(0, dirs->dir, args)) {
            data = mx_get_data_from_struct(dirs);
            if (data) {
                (*print)(data, args, dirs->dir);
                mx_del_str_arr(data);
            }
        }
    }
}
