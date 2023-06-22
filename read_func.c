#include "monty.h"
#include "lists.h"

/**
 * read_func - a function for selecting right functions
 * @parsed: a bytecode file line
 *
 * Return: a pointer else, NULL
 */
void (*read_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", handler_push},
		{"pall", handler_pall},
		{"pint", handler_pint},
		{"pop", handler_pop},
		{"swap", handler_swap},
		{"add", handler_add},
		{"nop", handler_nop},
		{"sub", handler_sub},
		{"div", handler_div},
		{"mul", handler_mul},
		{"mod", handler_mod},
		{"pchar", handler_pchar},
		{"pstr", handler_pstr},
		{"rotl", handler_rotl},
		{"rotr", handler_rotr},
		{"stack", handler_stack},
		{"queue", handler_queue},
		{NULL, NULL}
	};

	int codes = 17, a;

	for (a = 0; a < codes; a++)
	{
		if (strcmp(func_arr[a].opcode, parsed[0]) == 0)
		{
			return (func_arr[a].f);
		}
	}
	return (NULL);
}

/**
 * handler_push - a function for handling push
 * @stack: a pointer
 * @line_number: an int
 */
void handler_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, a;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		all_free(1);
		exit(EXIT_FAILURE);
	}

	for (a = 0; data.words[1][a]; a++)
	{
		if (isalpha(data.words[1][a]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			all_free(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = dnodeadd(stack, num);
	else if (data.qflag == 1)
		new = dnodeadd_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		all_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handler_pall - a function for handling pall
 * @stack: a pointer
 * @line_number: an int
 */
void handler_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		listprint(*stack);
}
