#include "libmx.h"

char *mx_strtrim(const char *str) {
    int len;
    char *dst;

    while (mx_is_whitespace(*str))
        str++;
    len = mx_strlen(str);
    while (mx_is_whitespace(str[len - 1])) {
        len--;
    }
    dst = mx_strnew(len);
    mx_strncpy(dst, str, len);
    return dst;
}
