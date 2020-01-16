#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int s1_len = mx_strlen(s1);
    int i;

    for (i = 0 ; s2[i] != '\0' ; i++)
        s1[s1_len + i] = s2[i];
    s1[s1_len + i] = '\0';
    return s1;
}
