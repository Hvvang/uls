#include "uls.h"

static void swap_str(char **str1, char** str2) {
    char *temp = *str1; 
    *str1 = *str2; 
    *str2 = temp; 
}

void mx_quicksort_r(char **arr, int left, int right) {
    if (left < right) {
        int low = left;
        int high = right;
        char* middle = arr[(low + high) / 2];

        while (low <= high) {
            while (mx_strcmp(arr[low], middle) > 0)
                low++;
            while (mx_strcmp(arr[high], middle) < 0)
                high--;
            if (low <= high) {
                swap_str(&arr[low], &arr[high]);
                low++;
                high--;
            }
        }
        mx_quicksort_r(arr, left, high);
        mx_quicksort_r(arr, low, right);
    }    
}
