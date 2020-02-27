#include "uls.h"

static void max_value(int *value, char *data) {
    int j = mx_strlen(data);

	if(*value < j)
        *value = j;
}

static void init_value(t_dirs *dir) {
    dir->total = 0;
    dir->max_group = 0;
    dir->max_user = 0;
    dir->max_size = 0;
    dir->max_link = 0;
    dir->max_time = 0;
}

void mx_get_max_value_in_dirs(t_dirs *dir) {
    t_dirs_entry *temp = dir->entry_dir;

    init_value(dir);
    while (temp) {
        max_value(&dir->max_group, temp->stat->group_name);
        if (temp->stat->user_name)
            max_value(&dir->max_user, temp->stat->user_name);
        if (temp->stat->permiss[0] == 'b' || temp->stat->permiss[0] == 'c')
            dir->max_size = 8;
        else
            max_value(&dir->max_size, temp->stat->file_size);
        max_value(&dir->max_link, temp->stat->nlink);
        if (temp->stat->time2)
            max_value(&dir->max_time, temp->stat->time2);
        dir->total += temp->stat->buf.st_blocks;
        temp = temp->next;
    }
}
