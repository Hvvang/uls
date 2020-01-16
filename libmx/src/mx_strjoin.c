#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
    int s1_len = (!s1) ? 0 : mx_strlen(s1);
    int s2_len = (!s2) ? 0 : mx_strlen(s2);
    char* res = mx_strnew(s1_len + s2_len);

    if (!s1 && !s2)
        return NULL;
    if (s1)
        mx_strcat(res, s1);
    if (s2)
        mx_strcat(res, s2);
    return res;
}
