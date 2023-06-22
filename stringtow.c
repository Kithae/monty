#include "monty.h"
#include "lists.h"

/**
 * word_count - a function that counts total string words
 * @s: the string
 *
 * Return: total words
 */
int word_count(char *s)
{
	int flag, a, b;

	flag = 0;
	b = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			b++;
		}
	}

	return (b);
}
/**
 * **stringtow - a function for splitting strings to words
 * @str: a string
 *
 * Return: an array pointer, else NULL
 */
char **stringtow(char *str)
{
	char **matrix, *tmp;
	int a, k = 0, length = 0, words, b = 0, start, end;

	length = strlen(str);
	words = word_count(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (a = 0; a <= length; a++)
	{
		if (isspace(str[a]) || str[a] == '\0' || str[a] == '\n')
		{
			if (b)
			{
				end = a;
				tmp = (char *) malloc(sizeof(char) * (b + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - b;
				k++;
				b = 0;
			}
		}
		else if (b++ == 0)
			start = a;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * everything_free - a function for freeing string arrays
 * @args: a strings array
 */
void everything_free(char **args)
{
	int a;

	if (!args)
		return;

	for (a = 0; args[a]; a++)
		free(args[a]);

	free(args);
}
