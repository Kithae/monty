#include "monty.h"
#include "lists.h"

data_t data = DATA_INIT;

/**
 * mymonty - a function that helps the main function
 * @args: a struct pointer
 *
*/
void mymonty(args_t *args)
{
	size_t length = 0;
	int read = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_number++;
		read = getline(&(data.line), &length, data.fptr);
		if (read < 0)
			break;
		data.words = stringtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			all_free(0);
			continue;
		}
		code_func = read_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_number, data.words[0]);
			all_free(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_number);
		all_free(0);
	}
	all_free(1);
}

/**
 * main - a function that inserts our monty bytecode interpreter
 * @argc: total arguments
 * @argv: arguments array
 *
 * Return: EXIT_SUCCESS else, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	args_t args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
