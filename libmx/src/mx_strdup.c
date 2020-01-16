#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *answer = mx_strnew(mx_strlen(s1));

    mx_strcpy(answer, s1);
    return answer;
}
