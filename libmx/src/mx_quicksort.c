#include "libmx.h"

static void mx_swap_and_count(char *s1, char *s2, int *count);

int mx_quicksort(char **arr, int left, int right) {
	int i = left;
	int j = right;
	int count = 0;

	if(!arr)
		return -1;
  	while (i <= j) {
    	while (mx_strlen(arr[i]) < mx_strlen(arr[(left + right) / 2]))
			i++;
    	while (mx_strlen(arr[j]) > mx_strlen(arr[(left + right) / 2]))
			j--;
 	   	if (i <= j)
			mx_swap_and_count(arr[i++], arr[j--], &count);
  	}
  	if (left < j)
    	mx_quicksort(arr, left, j);
  	if (i < right)
		mx_quicksort(arr, i, right);
 	return count;
}

static void mx_swap_and_count(char *s1, char *s2, int *count) {
	char *buf = s1;

	if (!s1 || !s2)
		return;
	s1 = s2;
	s2 = buf;
	*count = *count + 1;
}
