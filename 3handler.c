#include "monty.h"
#include "lists.h"

/**
 * handler_rotl - a function for handling rotl
 * @stack: a pointer
 * @line_number: an int
 */
void handler_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int a  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = read_index_dnode(*stack, 0);
	a = temp->n;
	del_index_dnode(stack, 0);
	dnodeadd_end(stack, a);
}

/**
 * handler_rotr - a function for handling rotr
 * @stack: a pointer
 * @line_number: an int
 */
void handler_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int a = 0, len = list_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = read_index_dnode(*stack, len - 1);
	a = temp->n;
	del_index_dnode(stack, len - 1);
	dnodeadd(stack, a);
}

/**
 * handler_stack - a function for handling stack
 * @stack: a pointer
 * @line_number: an int
 */
void handler_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * handler_queue - a function for handling queue
 * @stack: a pointer
 * @line_number: an int
 */
void handler_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
