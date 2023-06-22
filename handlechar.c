#include "monty.h"
#include "lists.h"

/**
 * handler_pchar - a function for handling pchar
 * @stack: a pointer
 * @line_number: an int
 */
void handler_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *nnode = *stack;

	if (!nnode)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	if (nnode->n < 0 || nnode->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	putchar(nnode->n);
	putchar('\n');
}

/**
 * handler_pstr - a function for handling pstr
 * @stack: a pointer
 * @line_number: an int
 */
void handler_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *nnode = *stack;

	(void)line_number;

	if (!nnode)
	{
		putchar('\n');
		return;
	}

	while (nnode && nnode->n != 0 && nnode->n >= 0 && nnode->n <= 127)
	{
		putchar(nnode->n);
		nnode = nnode->next;
	}

	putchar('\n');
}

