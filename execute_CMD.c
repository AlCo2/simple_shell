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
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("error");
		exit(1);
	}
	if (pid == 0)
	{
		if (execv(av[0], av) == -1)
		{	
			perror("Error");
			exit(1);
		}
	}else
	{
		wait(&status);
	}
}

