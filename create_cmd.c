#include "shell.h"

/**
 * create_cmd - function that create command with path and arg
 *
 * @token: the commnad and the args
 * @av_count: arguments counter
 *
 * Return: command created
*/
char **create_cmd(char *token, size_t *av_count)
{
	char **av = NULL;

	while (token != NULL)
	{
		(*av_count)++;
		av = (char **)malloc((*av_count) * sizeof(char *));
		if (av == NULL)
		{
			perror("out of memory");
			exit(1);
		}
		av[(*av_count) - 1] = malloc(strlen(token) + 1);
		if (av[(*av_count) - 1] == NULL)
		{
			perror("out of memory");
			exit(1);
		}
		strcpy(av[(*av_count) - 1], token);
		token = strtok(NULL, " ");
	}
	free(token);
	return (av);
}

