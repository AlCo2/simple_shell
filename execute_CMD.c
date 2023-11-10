#include "shell.h"

/**
 * executeCMD - function that execute the command
 *
 * @av: the command
 *
 * Return: nothing.
*/

void executeCMD(char **av, char *argv)
{
	if (execve(av[0], av, environ) == -1)
	{
		printf("%s: %d: %s: not found", argv, cmd_count, av[0]);
		exit(1);
	}
}

