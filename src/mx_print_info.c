#include "uls.h"

static void print_space(int max_elem, char* str) {
    for(int j = 0; j < max_elem - mx_strlen(str); j++) {
        mx_printchar(' ');
    }
}

static void print_lol(t_files *files) {
    mx_printstr(files->entry_file->stat->permiss);
    mx_printchar(' ');
    print_space(files->max_link, files->entry_file->stat->nlink);
    mx_printstr(files->entry_file->stat->nlink);
    mx_printchar(' ');
    mx_printstr(files->entry_file->stat->user_name);
    print_space(files->max_user, files->entry_file->stat->user_name);
    mx_printchar(' ');
    mx_printchar(' ');
}

void mx_print_info(t_files *files) {
    print_lol(files);
    mx_printstr(files->entry_file->stat->group_name);
    print_space(files->max_group, files->entry_file->stat->group_name);
    mx_printchar(' ');
    mx_printchar(' ');
    if (files->entry_file->stat->permiss[0] == 'b'
        || files->entry_file->stat->permiss[0] == 'c') {
        mx_printstr(files->entry_file->stat->rdev);
    }
    else {
        print_space(files->max_size, files->entry_file->stat->file_size);
        mx_printstr(files->entry_file->stat->file_size);
    }
}
