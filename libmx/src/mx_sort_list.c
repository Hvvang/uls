#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);
    t_list *crnt;
    t_list *crnt2;

    if (lst == NULL)
        return NULL;
    if (size == 1)
        return lst;
    for (crnt = lst; crnt != NULL; crnt = crnt->next) {
        for (crnt2 = lst; crnt2->next; crnt2 = crnt2->next) {
            if (cmp((void *)crnt2->data, (void *)crnt2->next->data)) {
            char *buf= crnt2->data;
            crnt2->data = crnt2->next->data;
            crnt2->next->data = buf;
            }
        }
    }
    return lst;
}
