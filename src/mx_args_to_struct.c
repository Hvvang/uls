#include "uls.h"

static int get_arg_info(t_args *args, char **argv, int index) {
    DIR *dir = opendir(argv[index]);
    int i = 1;
    struct stat buf;
    int lstat_h = lstat(argv[index], &buf);

    if (errno == 2)
        i = -1;
    else if (errno == 20) {
        if (lstat_h)
            i = -1;
        else
            i = 0;
    }
    if (i != -1 && args->fl[5] && (buf.st_mode & S_IFMT) == S_IFLNK)
        i = argv[index][mx_strlen(argv[index]) - 1] == '/' ? 1 : 0;
    if (dir)
        closedir(dir);
    errno = 0;
    return i;
}

static void push_arg_to_arr(char **arr, char *arg) {
    int i = 0;

    while (arr[i]) {
        i++;
    }
    arr[i] = mx_strdup(arg);
    arr[i + 1] = NULL;
}

static void mem_alloc_struct(t_args *args, char **files,
                             char **dirs, char **n_valid) {
    args->files = malloc(sizeof(char*) * (mx_arr_size(files) + 1));
    args->dirs = malloc(sizeof(char*) * (mx_arr_size(dirs) + 1));
    args->not_valid = malloc(sizeof(char*) * (mx_arr_size(n_valid) + 1));
    args->files[0] = NULL;
    args->dirs[0] = NULL;
    args->not_valid[0] = NULL;
}

static void parsing(char **files, char **dirs, char **n_valid, t_args *args) {
    int i = 0;
    int j = 0;
    int k = 0;

    mem_alloc_struct(args, files, dirs, n_valid);
    for (; files[i] || dirs[j] || n_valid[k]; ) {
        if (files[i]) {
            push_arg_to_arr(args->files, files[i]);
            i++;
        }
        if (dirs[j]) {
            push_arg_to_arr(args->dirs, dirs[j]);
            j++;
        }
        if (n_valid[k]) {
            push_arg_to_arr(args->not_valid, n_valid[k]);
            k++;
        }
    }
}


void mx_args_to_struct(int index, int argc, char **argv, t_args *args) {
    char **files = (char**)malloc(sizeof(char*) * (argc));
    char **dirs = (char**)malloc(sizeof(char*) * (argc + 1));
    char **not_valid = (char**)malloc(sizeof(char*) * (argc));

    files[0] = NULL;
    dirs[0] = (argc == index) ? mx_strdup(".") : NULL;
    dirs[1] = NULL;
    not_valid[0] = NULL;
    for (; index < argc; index++) {
        if (get_arg_info(args, argv, index) == -1)
            push_arg_to_arr(not_valid, argv[index]);
        else if (get_arg_info(args, argv, index) == 0)
            push_arg_to_arr(files, argv[index]);
        else
            push_arg_to_arr(dirs, argv[index]);
    }
    parsing(files, dirs, not_valid, args);
    mx_del_str_arr(files);
    mx_del_str_arr(dirs);
    mx_del_str_arr(not_valid);
}
