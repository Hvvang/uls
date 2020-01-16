#include "libmx.h"

static char *mx_get_new_len(const char *str, const char *sub,
const char *replace);

char *mx_replace_substr(const char *str, const char *sub,
const char *replace) {
    char *result = mx_get_new_len(str, sub, replace);
    int old_len = mx_strlen(sub);
    int new_len = mx_strlen(replace);
    int i = 0;

    if (!str || !sub || !replace)
        return NULL;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&result[i], replace);
            i += new_len;
            str += old_len;
        }
        else
            result[i++] = *str++;
    }
    result[i] = '\0';
    return result;
}

static char *mx_get_new_len(const char *str, const char *sub,
const char *replace) {
    int old_len = mx_strlen(sub);
    int i = 0;
    int count = 0;
    char *result;

    while (str[i++])
        if (mx_strstr(&str[i], sub) == &str[i]) {
            count++;
            i += old_len - 1;
        }
    result = mx_strnew(i + count * (mx_strlen(replace) - old_len) + 1);
    return result;
}
