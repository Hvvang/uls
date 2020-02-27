#include "uls.h"

static void print_space(int max_elem, char* str) {
    for(int j = 0; j < max_elem - mx_strlen(str); j++)
        mx_printchar(' ');
}

static void g_or_l(t_args * args, t_dirs *dirs, t_dirs_entry *temp) {
    if (args->fl[4] != 1) {
        mx_printstr(temp->stat->user_name);
        print_space(dirs->max_user, temp->stat->user_name);
        mx_printchar(' ');
        mx_printchar(' ');
    }
    if (args->fl[11] != 1) {
        mx_printstr(temp->stat->group_name);
        print_space(dirs->max_group, temp->stat->group_name);
        mx_printchar(' ');
        mx_printchar(' ');
    }
    if (args->fl[4] && args->fl[11]) {
        mx_printchar(' ');
        mx_printchar(' ');
    }
}

static void print_total(int sum_total) {
	mx_printstr("total ");
	mx_printint(sum_total);
	mx_printchar('\n');
}

static void print_info(t_dirs_entry *temp, t_dirs *dirs, t_args *args) {
	mx_printstr(temp->stat->permiss);
    mx_printchar(' ');
    print_space(dirs->max_link, temp->stat->nlink);
    mx_printstr(temp->stat->nlink);
    mx_printchar(' ');
    g_or_l(args, dirs, temp);
    if (temp->stat->permiss[0] == 'b' || temp->stat->permiss[0] == 'c')
    	mx_printstr(temp->stat->rdev);
    else {
        if (args->fl[12]) {
            mx_size_h(temp->stat->file_size);
        }
        else {
            print_space(dirs->max_size, temp->stat->file_size);
            mx_printstr(temp->stat->file_size);
        }
    }
}

void mx_print_dirs_ls(t_dirs *dirs, t_args *args) {
    t_dirs_entry *temp = dirs->entry_dir;

    mx_get_max_value_in_dirs(dirs);
	if (temp)
		print_total(dirs->total);
    while (temp) {
        print_info(temp, dirs, args);
        mx_printchar(' ');
        mx_time_dir(dirs, args, temp);
        mx_printchar(' ');
        mx_colored_name(args, temp->d_name, dirs->dir);
		if (temp->stat->name_link[0]) {
			mx_printstr(" -> ");
			mx_printstr(temp->stat->name_link);
		}
		mx_printchar('\n');
        temp = temp->next;
    }
}
