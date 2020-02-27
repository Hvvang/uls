#include "uls.h"

static void del_entry_dir(t_dirs_entry *entry_dir) {
    while (entry_dir) {
        t_dirs_entry *temp_entry = entry_dir->next;

        mx_strdel(&entry_dir->d_name);
        mx_del_stat_struct(entry_dir->stat);
        free(entry_dir);
        entry_dir = temp_entry;
    }
}

void mx_del_dirs_struct(t_dirs *dirs) {
    while (dirs) {
        t_dirs *temp_dir = dirs->next;

        mx_strdel(&dirs->dir);
        del_entry_dir(dirs->entry_dir);
        free(dirs);
        dirs = NULL;
        dirs = temp_dir;
    }
}

