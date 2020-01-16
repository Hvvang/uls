#include "libmx.h"

static char *mx_strtrim_symbol(const char *str, char c);
static char *mx_del_extra_symbols(const char *str, char c);
static char **mx_arrnew_by_words(const char *str, char c);
static char *mx_get_word(const char *str, char c, int *index);

char **mx_strsplit(const char *s, char c) {
    char *res = mx_del_extra_symbols(s, c);
    char **result = mx_arrnew_by_words(res, c);
    int index = 0;
    int i;

    if (!s)
        return NULL;
    for (i = 0; res[index]; i++) {
        result[i] = mx_get_word(res, c, &index);
    }
    result[i] = NULL;
    free(res);
    return result;
}

static char *mx_strtrim_symbol(const char *str, char c) {
    int len;
    char *dst;

    while (*str == c)
        str++;
    len = mx_strlen(str);
    while (str[len - 1] == c) {
        len--;
    }
    dst = mx_strnew(len);
    mx_strncpy(dst, str, len);
    return dst;
}

static char *mx_del_extra_symbols(const char *str, char c) {
    char *s;
    char *result;
    int count = 0;
    int i = 0;

    s = mx_strtrim_symbol((char*)str, c);
    for (;s[i]; i++)
        if (s[i] == c && s[i+1] == c)
            count++;
    result = mx_strnew(mx_strlen(s) - count + 1);
    for (i = 0; s[i]; i++)
        if (!(s[i] == c && s[i+1] == c))
            *result++ = s[i];
    *result = '\0';
    free(s);
    s = NULL;
    return result - (i - count);
}

static char **mx_arrnew_by_words(const char *str, char c) {
    int words = mx_count_words(str, c);
    char **result;

    result = (char **)malloc(sizeof(char *) * words + 1);
    return result;
}

static char *mx_get_word(const char *str, char c, int *index) {
    char strcp[mx_strlen(str)];
    int fn = *index;
    char *res;

    mx_strcpy(strcp, str);
    while (strcp[fn] && strcp[fn] != c)
        fn++;
    res = mx_strndup(&strcp[*index], fn - *index);
    *index = fn + 1;
    return res;
}
