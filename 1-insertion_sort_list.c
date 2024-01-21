#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly-linked list of integers in ascending
 *                       order using insertion sort algorithm
 * @list: head of doubly-linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr = *list;
	listint_t *next;

	while (curr != NULL)
	{
		next = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		sortinsert(&sorted, curr);
		curr = next;
	}
	*list = sorted;
}

/**
 * sortinsert - inserts a node in a sorted doubly-linked list
 * @list: sorted list
 * @node: node to insert
 *
 * Return: void
 */
void sortinsert(listint_t **list, listint_t *node)
{
	listint_t *temp;

	if (*list == NULL || (*list)->n >= node->n)
	{
		node->next = *list;
		if (*list != NULL)
			(*list)->prev = node;
		*list = node;
	}
	else
	{
		temp = *list;
		while (temp->next != NULL && temp->next->n < node->n)
			temp = temp->next;
		node->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = node;
		temp->next = node;
		node->prev = temp;
	}
}
