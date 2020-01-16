#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int word = 0;
    int res = 0;

    if (!str)
        return -1;
    for (;*str; ++str) {
        if (*str != c) {
            if (word == 0) {
                word = 1;
                res++;
            }
        }
        else if (word)
            word = 0;
    }
    return res;
}
