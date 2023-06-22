#include "monty.h"
#include "lists.h"

/**
 * insert_index_dnode - a function for inserting a node at specific index
 * @h: a list pointer
 * @idx: node index
 * @n: an integer
 *
 * Return: an address else, NULL
 */
dlistint_t *insert_index_dnode(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int a;
	dlistint_t *curr;
	dlistint_t *tmp = *h;

	if (idx == 0)
		return (dnodeadd(h, n));

	for (a = 0; tmp && a < idx; a++)
	{
		if (a == idx - 1)
		{
			if (tmp->next == NULL)
				return (dnodeadd_end(h, n));
			curr = malloc(sizeof(dlistint_t));
			if (!curr || !h)
				return (NULL);
			curr->n = n;
			curr->next = NULL;
			curr->next = tmp->next;
			curr->prev = tmp;
			tmp->next->prev = curr;
			tmp->next = curr;
			return (curr);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}

/**
 * dnodeadd_end - a function for adding a new node
* in a doubly linked list at the end
 * @head: a pointer
 * @n: an integer
 *
 * Return: an address else, NULL
 */
dlistint_t *dnodeadd_end(dlistint_t **head, const int n)
{
	dlistint_t *curr;
	dlistint_t *tmp = *head;

	if (!head)
		return (NULL);

	curr = malloc(sizeof(dlistint_t));
	if (!curr)
		return (NULL);

	curr->n = n;
	curr->next = NULL;

	if (*head == NULL)
	{
		curr->prev = NULL;
		*head = curr;
		return (curr);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = curr;
	curr->prev = tmp;

	return (curr);
}

/**
 * dlistfree - a function for freeing a doubly linked list
 * @head: a pointer
 */
void dlistfree(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
