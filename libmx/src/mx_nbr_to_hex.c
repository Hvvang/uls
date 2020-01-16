#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char prev_res[8];
    char *res;
    int i = 0;
    int temp;

    if (nbr == 0)
        prev_res[i++] = nbr + 48;
    while (nbr != 0) {
        temp = nbr % 16;
        prev_res[i++] = (temp < 10) ? temp + 48 : temp + 55;
        nbr /= 16;
    }
    mx_str_reverse(prev_res);
    res = mx_strndup(prev_res, i);
    return res;
}
