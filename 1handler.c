#include "monty.h"
#include "lists.h"

/**
 * handler_pint - a function for handling pint
 * @stack: a pointer
 * @line_number: an int
 */
void handler_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *nhead = *stack;

	if (!nhead)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", nhead->n);
}

/**
 * handler_pop - a function for handling pop
 * @stack: a pointer
 * @line_number: an int
 */
void handler_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ntemp = *stack;

	if (!ntemp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	del_index_dnode(stack, 0);
}

/**
 * handler_swap - a function for handling swap
 * @stack: a pointer
 * @line_number: an int
 */
void handler_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ntemp = *stack, *node = NULL;
	int a;

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	ntemp = read_index_dnode(*stack, 0);
	a = ntemp->n;
	del_index_dnode(stack, 0);
	node = insert_index_dnode(stack, 1, a);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_add - a function for handling add
 * @stack: a pointer
 * @line_number: an int
 */
void handler_add(stack_t **stack, unsigned int line_number)
{
	int tally = 0;
	stack_t *node = NULL;
	stack_t *node_0 = read_index_dnode(*stack, 0);
	stack_t *node_1 = read_index_dnode(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	tally = node_0->n + node_1->n;
	del_index_dnode(stack, 0);
	del_index_dnode(stack, 0);
	node = dnodeadd(stack, tally);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_nop - a function for handling nop
 * @stack: a pointer
 * @line_number: an int
 */
void handler_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
