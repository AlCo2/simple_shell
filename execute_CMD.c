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
	if (execve(av[0], av, environ) == -1)
	{	
		perror("Error");
		exit(1);
	}
}

