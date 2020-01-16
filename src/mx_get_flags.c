#include "uls.h"

static bool is_flag(char *flag);
static void amount_of_flags(int *amount, char *flag);
static char *parse_to_arr(int index, char **argv, int amount);

char *mx_get_flags(int *index, int argc, char **argv) {
	int amount = 0;
	char *flags;

	while (*index < argc && argv[*index][0] == '-' ) {
		if (is_flag(argv[*index])) {
			amount_of_flags(&amount, argv[*index]);
			(*index)++;
		}
		else
			break;
	}
	flags = parse_to_arr(*index, argv, amount);
	return flags;
}

static bool is_flag(char *flag) {
	for (int i = 1; flag[i]; i++) {
		if (flag[i] == '-')
			return false;
	}
	return true;
}

static void amount_of_flags(int *amount, char *flag) {
	*amount += mx_strlen(flag) - 1;
}

static char *parse_to_arr(int index, char **argv, int amount) {
	if (index != 1) {
		char *flags = mx_strnew(amount);
		int i = 1;
		int j = 1;
		int k = 0;

		for (; i < index; i++) {
			for (j = 1; argv[i][j + 1]; j++) {
				flags[k++] = argv[i][j + 1];
			}
		}
		return flags;
	}
	return NULL;
}

