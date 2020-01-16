#include "libmx.h"

bool mx_is_whitespace(char c) {
    if (c == ' ' || c == '\t' || c == '\n'
        || c == '\v' || c == '\f' || c == '\r') {
        return 1;
    }
    return 0;
}
