#include "shell.h"

/**
 * executeCMD - function that execute the command
 *
 * @av: the command
 *
 * Return: nothing.
*/

void executeCMD(char **av)
{
	if (fork() == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
}

