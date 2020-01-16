#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int i;
    int j;

    for (i = 0; haystack[i]; i++) {
        for (j = 0; haystack[i + j] == needle[j] && needle[j]; j++) {
            if (haystack[i + j] == needle[j] && !needle[j + 1]) {
                return (char *)haystack + i;
            }
        }
    }
    return NULL;
}
