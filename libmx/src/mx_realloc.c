#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    char *temp = (char*) malloc(sizeof(char) * size + 1);

    if (temp == NULL)
        return NULL;
    mx_memcpy(temp, ptr, malloc_size(ptr));
    free(ptr);
    return temp;
}
