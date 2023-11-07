#include "shell.h"

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

