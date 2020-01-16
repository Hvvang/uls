#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double answer = n;

    if (pow == 0)
        return 1;
    for (unsigned int i = 1; i < pow; i++)
        answer = answer * n;
    return answer;
}
