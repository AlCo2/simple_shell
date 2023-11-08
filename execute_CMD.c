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
	if (execv(av[0], av) == -1)
	{	
		perror("Error");
		exit(1);
	}
}

