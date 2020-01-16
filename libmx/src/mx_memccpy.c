#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n) {
    unsigned char* ptr_dst = dst;
    const unsigned char* ptr_src = src;
    size_t i = 0;

    c = (unsigned char)c;
    while (i < n) {
        ptr_dst[i] = ptr_src[i];
        if (ptr_src[i] == c)
            return ptr_dst+i+1;
        i++;
    }
    if (i == n && ptr_src[i] != c)
        return NULL;
    return NULL;
}
