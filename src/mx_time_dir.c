#include "uls.h"

static void print_space(int max_elem, char* str) {
    for(int j = 0; j < max_elem - mx_strlen(str); j++)
        mx_printchar(' ');
}

void mx_time_dir(t_dirs *dirs, t_args *args, t_dirs_entry *temp) {
	if (args->fl[10] == 1)
            mx_printstr(temp->stat->time1);
    else {
    	mx_printstr(temp->stat->time1);
    	print_space(dirs->max_time, temp->stat->time2);
    	if (dirs->max_time == 5)
			mx_printchar(' ');
    	mx_printstr(temp->stat->time2);
    }
}
