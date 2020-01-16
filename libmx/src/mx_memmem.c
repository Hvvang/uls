#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
const void *little, size_t little_len) {
    char* haystack = (char*)big;
    char* needle = (char*)little;
    size_t i;
    size_t j;

    for (i = 0; i < big_len; i++) {
        for (j = 0; haystack[i+j] == needle[j] && j < little_len; j++) {
            if (haystack[i+j] == needle[j] && !needle[j+1])
                return (char*)haystack+i;
        }
    }
    return NULL;
}
