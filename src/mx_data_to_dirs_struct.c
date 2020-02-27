#include "uls.h"

static int count_el(t_args *args, char *dir_name) {
	DIR *dir = opendir(dir_name);
	struct dirent *entry = NULL;
	int count = 0;

	while (dir && ((entry = readdir(dir)) != NULL)) {
		if (!args->fl[3] && entry->d_name[0] == '.')
			continue;
		count++;
	}
	if (dir)
		closedir(dir);
	return count;
}

static char **data_to_arr(t_args *args, char *dir_name) {
	DIR *dir = opendir(dir_name);
	struct dirent *entry = NULL;
	char **data = NULL;
	
	if (dir) {
		int size = count_el(args, dir_name) + 1;

		data = (char**)malloc(sizeof(char*) * size);
		size = 0;
		while (dir && ((entry = readdir(dir)) != NULL)) {
			if (!args->fl[3] && entry->d_name[0] == '.')
				continue ;
			data[size++] = mx_strdup(entry->d_name);
		}
		data[size] = NULL;
		mx_sort_data(args, data);
		closedir(dir);
	}
	return data;
}

t_dirs *mx_data_to_dirs_struct(t_args *args, char *dir_name) {
	t_dirs *temp = malloc(sizeof (t_dirs));
	char **data = data_to_arr(args, dir_name);
	int i = 0;

	temp->entry_dir = NULL;
	if (data) {
		for (; data[i]; i++)
			temp->entry_dir = mx_add_dirs_entry(args, temp->entry_dir,
												data[i], dir_name);
		if (args->fl[4] || args->fl[5] || args->fl[11])
			mx_get_max_value_in_dirs(temp);
		mx_del_str_arr(data);
	}
	temp->dir = mx_strdup(dir_name);
	temp->next = NULL;
	return temp;
}
