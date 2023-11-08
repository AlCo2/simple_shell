#include "shell.h"

/**
 * create_cmd - function that create command with path and arg
 *
 * @token: the commnad and the args
 * @av_count: arguments counter
 *
 * Return: command created
*/
char **create_cmd(char *token, char **path)
{
	char **av = NULL;
	char *result = NULL;

	av = split_string(token, " ");
	result = check_path(token, path);
	if (result)
	{
		av[0] = malloc(strlen(result) + 1);
		strcpy(av[0], result);
		free(result);
	}
	return (av);
}

