#include "shell.h"

/**
 * executeCMD - function that execute the command
 *
 * @av: the command
 * @argv: the program name
 * @cmd_count: number total for command entered
 *
 * Return: nothing.
*/

void executeCMD(char **av, char *argv, int cmd_count)
{
	if (execve(av[0], av, environ) == -1)
	{
		printf("%s: %d: %s: not found\n", argv, cmd_count, av[0]);
		exit(1);
	}
}

