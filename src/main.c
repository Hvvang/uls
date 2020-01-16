#include "uls.h"

int main(int argc, char **argv) {
	int index = 1;
	char *flags = mx_get_flags(&index, argc, argv);
	int size = 0;
	mx_check_dirs(index, argc, argv);

	for (int i = 0; flags[i]; i++) {
		for (int j = i + 1; flags[j]; j++) {
			if (flags[j] == flags[i]) {
				size++;
				flags[j] = '0';
			}
		}
	}
	char uniq_flags[mx_strlen(flags) - size];
	int j = 0;
	for (int i = 0; flags[i]; i++) {
		if (flags[i] != '0')
			uniq_flags[j] = flags[i];
	}

	for (int i = 0; uniq_flags[i]; i++) {
		for (int j = 0; LEGAL[j]; j++) {
			if (uniq_flags[i] == LEGAL[j])
				break;
			else if (!LEGAL[j + 1]) {
				char *error = "uls: illegal option --"; 
				write(2, error, mx_strlen(error));
				write(2, &uniq_flags[i], 1);
				write(2, "\n", 1);
				char *msg = "usage: uls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]";
				write(2, msg, mx_strlen(msg));		
			} 
		}
	}
	return 0;
}

