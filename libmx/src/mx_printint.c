#include "libmx.h"

void mx_printint(int n) {
    if (n == -2147483648)
        write(1, "-2147483648", 11);
    if (n < 0 && n > -2147483648) {
        n = -n;
        mx_printchar('-');
        mx_printint(n);
    }
    else {
        if (n < 10 && n >= 0)
            mx_printchar(n + '0');
        if (n > 9) {
            mx_printint(n/10);
            mx_printchar(n % 10 + '0');
        }
    }
}
