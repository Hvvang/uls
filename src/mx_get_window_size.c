#include "uls.h"

int mx_get_window_size(t_args *args) {
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if (!isatty(1) && (args->fl[0] || args->fl[6])) {
        return 80;
    }
	return w.ws_col;
}
