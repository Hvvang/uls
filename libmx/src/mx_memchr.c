#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char* str = (void*)s;
    size_t i = 0;

    while (n) {
        if (str[i] == c)
            return &str[i];
        n--;
        i++;
    }
    return NULL;
}
