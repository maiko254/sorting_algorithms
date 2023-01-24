#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: pointer to the doubly linked list to sort
	 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;

	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->prev = current->next = NULL;

		sorted_insert(&sorted, current);

		current = next;
		print_list((const listint_t *)*list);
	}
}

/**
 * sorted_insert - inserts nodes in a sorted ways
 *
 * @list: list to sort
 * @newnode: node to insert
 */
void sorted_insert(listint_t **list, listint_t *newnode)
{
	listint_t *current;

	if (*list == NULL)
		*list = newnode;
	else if ((*list)->n >= newnode->n)
	{
		newnode->next = *list;
		newnode->next->prev = newnode;
		*list = newnode;
	}
	else
	{
		current = *list;

		while (current->next != NULL &&
			current->next->n < newnode->n)
			current = current->next;

		newnode->next = current->next;

		if (current->next != NULL)

			newnode->next->prev = newnode;

		current->next = newnode;
		newnode->prev = current;
	}
}
