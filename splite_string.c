#include "shell.h"

/**
 * split_string - function to split string into a list
 *
 * @input: the string
 * @delim: the delim
 *
 * Return: the List
*/

char **split_string(char *input, char *delim)
{
	char **list = NULL;
	int i = 0;
	char *token = strtok(input, delim);

	while (token != NULL)
	{
		list = realloc(list, (i + 1) * sizeof(char *));
		if (list == NULL)
		{
			perror("out of memory");
			exit(1);
		}
		list[i] = malloc(strlen(token) + 1);
		if (list[i] == NULL)
		{
			perror("out of memory");
			exit(1);
		}
		strcpy(list[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	list[i] = NULL;
	return (list);
}

