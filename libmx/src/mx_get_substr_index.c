#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int i;
    int j;

    if (!str || !sub)
        return -2;
    for (i = 0; str[i]; i++) {
        for (j = 0; str[i+j] == sub[j] && sub[j]; j++) {
            if (str[i+j] == sub[j] && !sub[j+1])
                return i;
        }
    }
    return -1;
}
