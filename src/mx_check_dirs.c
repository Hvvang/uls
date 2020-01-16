#include "uls.h"

static void check_on_exist(char *flag, int *existing);
static void show_existing(char *flag, int *existing);

void mx_check_dirs(int index, int argc, char **argv) {
	if (index < argc) {	
		char *entry[argc - index + 1];
		int existing_arr[argc - index];
		int i;

		for (i = 0; index + i < argc; i++) {
			entry[i] = mx_strdup(argv[index + i]);
		}
		entry[argc - index] = NULL;
		mx_bubble_sort(entry, argc - index);
		for (i = 0; index + i < argc; i++) {
			check_on_exist(entry[i], &existing_arr[i]);
		}
		for (i = 0; index + i < argc; i++) {
    	    show_existing(entry[i], &existing_arr[i]);
    	}	
		return ;
	}
}

static void check_on_exist(char *flag, int *existing) {
	DIR *directory = opendir(flag);
	
	*existing = 0;
	if (directory == NULL) {
		*existing = -1;
		mx_printstr("uls: ");
		perror(flag);
		return ;
	}
	(void)closedir(directory);
}

static void show_existing(char *flag, int *existing) {
	if (*existing == 0) {
	    DIR *directory = opendir(flag);
    	struct dirent *drt;	
		
		while ((drt = readdir(directory)) != NULL) {
			mx_printstr(drt->d_name);
			mx_printchar('\t');
		}
		(void)closedir(directory);
	}
}

