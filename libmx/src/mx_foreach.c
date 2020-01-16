#include "libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) {
    int i;
    
    for (i = 0; i < size; i++)
        f(arr[i]);
}
