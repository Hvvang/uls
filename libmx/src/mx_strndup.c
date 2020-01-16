#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t i;
    char* str = mx_strnew(n);

    for(i = 0; i < n; i++) {
        str[i] = s1[i];
    }
    str[i] = '\0';
    return str;
}
