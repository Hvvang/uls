#include "libmx.h"

static char *mx_whitespace_to_space(const char *str);
static int mx_str_size(char *s);

char *mx_del_extra_spaces(const char *str) {
    int count = 0;
    int i = 0;
    char *s;
    char *result;

    if (!str)
        return NULL;
    s = mx_whitespace_to_space(str);
    count = mx_str_size(s);
    result = mx_strnew(mx_strlen(s) - count + 1);
    for (i = 0; s[i]; i++)
        if (!(s[i] == ' ' && s[i + 1] == ' '))
            *result++ = s[i];
    *result = '\0';
    free(s);
    s = NULL;
    return result - (i - count);
}

static char *mx_whitespace_to_space(const char *str) {
    int i;
    char strcpy[mx_strlen(str)];

    mx_strcpy(strcpy, str);
    for (i = 0; strcpy[i]; i++)
        if (mx_is_whitespace(strcpy[i]))
            strcpy[i] = ' ';
    return mx_strtrim(strcpy);
}

static int mx_str_size(char *s) {
    int count = 0;
    int i;

    for (i = 0; s[i]; i++)
        if (s[i] == ' ' && s[i + 1] == ' ')
            count++;
    return count;
}
