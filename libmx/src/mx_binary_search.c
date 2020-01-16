#include "libmx.h"

static void onError(char **arr, int size, const char *s, int right);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int mid = (right + left) / 2;

    onError(arr, size, s, right);
    while (right >= left) {
        (*count)++;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        else if (mx_strcmp(arr[mid], s) > 0) {
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else {
            left = mid + 1;
            mid = (right + left) / 2;
        }
    }
    *count = 0;
    return -1;
}

static void onError(char **arr, int size, const char *s, int right) {
    if (mx_strcmp(arr[right], s) < 0 || size < 1) {
        exit(-1);
    }
}
