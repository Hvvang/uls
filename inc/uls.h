#ifndef ULS_H
#define ULS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "./libmx/inc/libmx.h"
#include <dirent.h>

#define LEGAL "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1"

typedef struct s_flags {
	char *flags;
} t_flags;

void mx_check_dirs(int index, int argc, char **argv);
char *mx_get_flags(int *index, int argc, char **argv);

#endif
