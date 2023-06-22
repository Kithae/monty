#include "monty.h"

/**
 * list_len - a function for returning total nodes
 * @h: a list pointer
 *
 * Return: total nodes
 */
size_t list_len(const dlistint_t *h)
{
	size_t nnode = 0;

	if (!h)
		return (0);

	while (h)
	{
		nnode++;
		h = h->next;
	}

	return (nnode);
}

/**
 * dnodeadd - a function for adding nodes
*at the beginning of a linked list, doubly
 * @head: a pointer
 * @n: an integer
 *
 * Return: an address else, or NULL
 */
dlistint_t *dnodeadd(dlistint_t **head, const int n)
{
	dlistint_t *curr;

	if (!head)
		return (NULL);

	curr = malloc(sizeof(dlistint_t));
	if (!curr)
		return (NULL);

	curr->n = n;

	curr->next = *head;
	curr->prev = NULL;

	if (*head)
		(*head)->prev = curr;

	*head = curr;

	return (curr);
}

/**
 * listprint - a function for printing doubly linked list
 * @h: a list pointer
 *
 * Return: total list nodes
 */
size_t listprint (const dlistint_t *h)
{
	size_t nnode = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nnode++;
	}

	return (nnode);
}

/**
 * del_index_dnode - a function for deleting a node
 * at a specific indexin double linked lists
 * @head: a pointer
 * @index: node index
 *
 * Return: 1 else, -1
 */
int del_index_dnode(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	unsigned int a = 0;

	if (!index)
	{
		(*head) = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		return (1);
	}

	while (a < index)
	{
		tmp = tmp->next;
		a++;
		if (!tmp)
			return (0);
	}

	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);

	return (1);
}

/**
 * read_index_dnode - a function for getting the nth node
 * @head: a pointer
 * @index: node index
 *
 * Return: an address else, NULL
 */
dlistint_t *read_index_dnode(dlistint_t *head, unsigned int index)
{
	unsigned int a = 0;

	if (!head)
		return (NULL);

	while (head && a < index)
	{
		head = head->next;
		a++;
	}

	return (head ? head : NULL);
}
