#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *temp = list;
    int count = 0;

    while (temp != NULL && temp->next) {
        temp = temp->next;
        count++;
    }
    if (count)
        count++;
    return count;
}
