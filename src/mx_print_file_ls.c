#include "uls.h"

static t_file_entry *pushing_data(t_args *args, char *file) {
    t_file_entry *entry_file = malloc(sizeof(t_file_entry));

    entry_file->files = mx_strdup(file);
    entry_file->stat = mx_get_stat(args, file);
    entry_file->next = NULL;
    return entry_file;
}

static t_file_entry *get_files_entry(t_args *args, t_file_entry *entry_file,
                                     char *file) {
    t_file_entry *current  = entry_file;

    if (!entry_file)
        return pushing_data(args, file);
    while (current->next != NULL)
        current = current->next;
    current->next = pushing_data(args, file);
    return entry_file;
}

static t_files *get_files(t_args *args, char **files) {
    int i = 0;
    t_files *files_st = malloc(sizeof(t_files));

    files_st->entry_file = NULL;
    while (files[i]) {
        files_st->entry_file = get_files_entry(args, files_st->entry_file,
                                               files[i]);
        i++;
    }
 return files_st;
}

static void time_file(t_args *args, t_files *files) {
    if (args->fl[10] == 1)
        mx_printstr(files->entry_file->stat->time1);
    else {
        mx_printstr(files->entry_file->stat->time1);
        mx_print_space_file(files->max_time,
                            files->entry_file->stat->time2);
        mx_printstr(files->entry_file->stat->time2);
        }
}


void mx_print_file_ls(t_args *args) {
    t_files *files = get_files(args, args->files);
    t_file_entry *temp_entry = files->entry_file;

    mx_get_max_value_in_files(files);
    while (temp_entry) {
        mx_print_info_file(args, files);
        mx_printchar(' ');
        time_file(args, files);
        mx_printchar(' ');
        mx_colored_name(args, temp_entry->files, NULL);
    	if (temp_entry->stat->name_link[0]) {
    		mx_printstr(" -> ");
    		mx_printstr(temp_entry->stat->name_link);
    	}
    	mx_printchar('\n');
    	temp_entry = temp_entry->next;
	}
    mx_del_files_struct(files);

}
