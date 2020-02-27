#include "uls.h"

static void del_entry_file(t_file_entry *entry_file) {

    while (entry_file) {
        t_file_entry *temp_entry = entry_file->next;

        mx_strdel(&entry_file->files);
        mx_del_stat_struct(entry_file->stat);
        free(entry_file);
        entry_file = temp_entry;
    }
}

void mx_del_files_struct(t_files *files) {

    del_entry_file(files->entry_file);
    free(files);
    files = NULL;
}
