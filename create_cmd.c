#include "shell.h"

/**
 * create_cmd - function that create command with path and arg
 *
 * @token: the commnad and the args
 * @av_count: arguments counter
 *
 * Return: command created
*/
char **create_cmd(char *token)
{
	char **av = NULL;
	
	av = split_string(token, " ");
	return (av);
}

