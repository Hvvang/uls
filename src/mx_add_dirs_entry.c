#include "uls.h"

static t_dirs_entry *mx_pushing_data(t_args *args, char *data, char *dir) {
    t_dirs_entry *temp = malloc(sizeof(t_dirs_entry));
    char *res = (mx_strcmp(dir, "/")) ? mx_strjoin(dir, "/") : mx_strdup(dir);
    char *tmp = NULL;
    DIR *t_dir = opendir(dir);

    temp->d_name = mx_strdup(data);
    tmp = mx_strjoin(res, temp->d_name);
    temp->stat = (args->fl[1] || args->fl[4] || args->fl[5]
                  || args->fl[11]) ? mx_get_stat(args, tmp) : NULL;
    mx_strdel(&res);
    mx_strdel(&tmp);
    temp->next = NULL;
    if (dir)
        closedir(t_dir);
    return temp;
}

t_dirs_entry *mx_add_dirs_entry(t_args *args, t_dirs_entry *dirs_entry,
                                char *data, char *dir) {
	t_dirs_entry *current = dirs_entry;

    if (!dirs_entry)
        return mx_pushing_data(args, data, dir);
    while (current->next != NULL)
        current = current->next;
    current->next = mx_pushing_data(args, data, dir);
    return dirs_entry;
}
