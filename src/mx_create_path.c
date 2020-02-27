#include "uls.h"

char *mx_create_path(char *part_a, char *part_b) {
    char *tmp = mx_strjoin(part_a, "/");
    char *path = mx_strjoin(tmp, part_b);

    mx_strdel(&tmp);
    return path;
}
