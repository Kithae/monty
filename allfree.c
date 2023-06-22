#include "monty.h"
#include "lists.h"

/**
 * all_free - a function for handling custom memory
 * @all: flags
 */
void all_free(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		everything_free(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			dlistfree(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
