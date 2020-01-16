#include "libmx.h"

int mx_sqrt(int x) {
    int search = x / 3;

    if (x > 99)
        search = x / 10;
    if (x == 1)
        return 1;
    else if (x == 4)
        return 2;
    else {
        for (int i = 1; i <= search && i <= 46340; i++) {
            if (i * i == x)
                return i;
        }
    }
    return 0;
}
