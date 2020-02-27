#include "uls.h"

static void dir_colors(t_file *file_st) {
    if (file_st->permiss[8] == 'w' && (file_st->permiss[9] == 't'
        || file_st->permiss[9] == 'T'))
        mx_printstr("\x1B[0;30;42m");
    else if (file_st->permiss[8] == 'w' && file_st->permiss[9] == 'x')
        mx_printstr("\033[30;43m");
    else
        mx_printstr("\x1B[34m");
}

void mx_color_output(t_file *file_st) {
    if (file_st->permiss[3] == 's' || file_st->permiss[3] == 'S')
        mx_printstr("\033[30;41m");
    else if (file_st->permiss[6] == 's' || file_st->permiss[6] == 'S')
        mx_printstr("\033[30;46m");
    else if (file_st->permiss[0] == 'b')
        mx_printstr("\033[34;46m");
    else if (file_st->permiss[0] == 'c')
        mx_printstr("\033[34;43m");
    else if (file_st->permiss[0] == 'd')
        dir_colors(file_st);
    else if (file_st->permiss[0] == 'l')
        mx_printstr("\033[35m");
    else if (file_st->permiss[0] == 's')
        mx_printstr("\033[32m");
    else if (file_st->permiss[0] == 'p')
        mx_printstr("\033[33m");
    else if (file_st->permiss[0] == 'w')
        mx_printstr("\033[36m");
    else if (file_st->permiss[3] == 'x')
        mx_printstr("\033[31m");
}
