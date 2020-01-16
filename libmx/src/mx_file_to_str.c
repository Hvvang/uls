#include "libmx.h"

static int mx_count_bytes(int fd_dst);

char *mx_file_to_str(const char *file) {
    int cntr = 0;
    int rd;
    char *new_str;
    int fd_dst = open(file, O_RDONLY);

    if (fd_dst < 0)
        return NULL;
    cntr = mx_count_bytes(fd_dst);
    if (cntr > 0) {
        fd_dst = open(file, O_RDONLY);
        new_str = mx_strnew(cntr + 1);
        rd = read(fd_dst, new_str, cntr);
        *(new_str + cntr) = '\0';
        return new_str;
    }
    return NULL;
}

static int mx_count_bytes(int fd_dst) {
    int cntr = 0;
    char buf[1];
    int rd;

    while ((rd = read(fd_dst, buf, 1)) && buf[0] != EOF) {
        cntr++;
    }
    close(fd_dst);
    return cntr;
}
