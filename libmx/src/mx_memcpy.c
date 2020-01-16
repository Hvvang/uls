#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *ptr_dst = (char *)dst;
    char *ptr_src = (char *)src;
    size_t i = 0;

    while (i < n) {
        ptr_dst[i] = ptr_src[i];
        i++;
    }
    return dst;
}
