#include "monty.h"
#include "lists.h"

/**
 * handler_sub - a function for handling sub
 * @stack: a pointer
 * @line_number: an int
 */
void handler_sub(stack_t **stack, unsigned int line_number)
{
	int subtract = 0;
	stack_t *node = NULL;
	stack_t *node_0 = read_index_dnode(*stack, 0);
	stack_t *node_1 = read_index_dnode(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	subtract = node_1->n - node_0->n;
	del_index_dnode(stack, 0);
	del_index_dnode(stack, 0);
	node = dnodeadd(stack, subtract);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_div - a function for handling div
 * @stack: a pointer
 * @line_number: an int
 */
void handler_div(stack_t **stack, unsigned int line_number)
{
	int divide = 0;
	stack_t *node = NULL;
	stack_t *node_0 = read_index_dnode(*stack, 0);
	stack_t *node_1 = read_index_dnode(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	divide = node_1->n / node_0->n;
	del_index_dnode(stack, 0);
	del_index_dnode(stack, 0);
	node = dnodeadd(stack, divide);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_mul - a function for handling mul
 * @stack: a pointer
 * @line_number: an int
 */
void handler_mul(stack_t **stack, unsigned int line_number)
{
	int multiply = 0;
	stack_t *node = NULL;
	stack_t *node_0 = read_index_dnode(*stack, 0);
	stack_t *node_1 = read_index_dnode(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	multiply = node_1->n * node_0->n;
	del_index_dnode(stack, 0);
	del_index_dnode(stack, 0);
	node = dnodeadd(stack, multiply);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_mod - a function for handling mod
 * @stack: a pointer
 * @line_number: an int
 */
void handler_mod(stack_t **stack, unsigned int line_number)
{
	int modulus = 0;
	stack_t *node = NULL;
	stack_t *node_0 = read_index_dnode(*stack, 0);
	stack_t *node_1 = read_index_dnode(*stack, 1);

	if (list_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	modulus = node_1->n % node_0->n;
	del_index_dnode(stack, 0);
	del_index_dnode(stack, 0);
	node = dnodeadd(stack, modulus);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}
