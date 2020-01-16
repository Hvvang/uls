#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    char *buf;
    int i;

    if (!str || !sub)
        return -1;
    for (i = 0; str[i]; i++) {
        if (str[i] == sub[0]) {
            buf = (char*)str+i;
            if (mx_strstr(buf, sub) != NULL) {
                count++;
                i += mx_strlen(sub);
            }
        }
    }
    return count;
}
