#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* str = (void*)s;
    size_t i = mx_strlen((char*)str);

    while (n) {
      if (str[i] == c)
        return &str[i];
      n--;
      i--;
    }
    return NULL;
}
