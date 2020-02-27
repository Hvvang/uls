#include "uls.h"

static void get_time(t_args *args, t_file *file_st) {
    char* str = ctime(&file_st->buf.st_mtime);
    time_t current = time(NULL);

    if (args->fl[10] == 1) {
        file_st->time1 = mx_strndup(&str[4], mx_strlen(&str[4]) - 1);
        file_st->time2 = NULL;
    }
    else {
        str += 4;
        if (current - file_st->buf.st_mtime >= 31536000 / 2 ) {
            file_st->time1 = mx_strndup(str, 6);
            file_st->time2 = mx_strndup(str + 15, 5);
        }
        else {
            file_st->time1 = mx_strndup(str, 6);
            file_st->time2 = mx_strndup(str + 6, 6);
        }
    }
}

t_file *mx_get_stat(t_args *args, char *data) {
    t_file *stat = malloc(sizeof (t_file));
    struct group *group;

    lstat(data, &stat->buf);
	stat->permiss = mx_permission(data, stat);
	stat->nlink = mx_itoa(stat->buf.st_nlink);
	stat->pw = getpwuid(stat->buf.st_uid);
	stat->user_name = mx_strdup(stat->pw->pw_name);
    group = getgrgid(stat->buf.st_gid);
    if (group != NULL)
        stat->group_name = mx_strdup(group->gr_name);
    else
        stat->group_name = mx_itoa(stat->buf.st_gid);
   	stat->rdev = mx_major_minor_size(stat);
	stat->file_size = mx_itoa(stat->buf.st_size);
	get_time(args, stat);
	stat->file_name = mx_strdup(data);
    stat->name_link = mx_strnew(stat->buf.st_size);
    readlink(data, stat->name_link, 1024);
    return stat;
}
