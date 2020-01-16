#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *str1 = (void *)s1;
    unsigned char *str2 = (void *)s2;
    size_t i = 0;

    while (i < n && str1[i] == str2[i])
        i++;
    return str1[i] - str2[i];
}
