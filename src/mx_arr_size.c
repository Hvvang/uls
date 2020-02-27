#include "uls.h"

int mx_arr_size(char **arr) {
    int i = 0;

    if (arr) {
        while (arr[i])
            i++;
    }
    return i;
}
