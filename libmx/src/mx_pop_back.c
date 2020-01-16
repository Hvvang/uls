#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *current;

	if (!head && !(*head))
		return;
	if ((*head)->next == NULL) {
		(*head)->data = NULL;
		free(*head);
		return;
	}
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	current->next->data = NULL;
	free(current->next);
	current->next = NULL;
}
