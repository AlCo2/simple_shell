#include "shell.h"

/**
 * main - the main function that run the loop for the shell
 *
 * Return: (0)
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char **PATHS = create_path_list();
	int i;
	
	(void)argc;
	(void)argv;
	while (1)
	{
		printf("\n$ ");
		nread = getline(&line, &len, stdin);
		if(nread == -1)
		{
			break;
		}
		line[nread - 1] = '\0';
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			i = 0;
			while (PATHS[i])
			{
				free(PATHS[i]);
				i++;
			}
			free(PATHS);
			break;
		}
		if(line[0] == 'c' && line[1] == 'd' && line[2] == ' ')
		{
			printf("changed directory: %s\n", line+3);
			continue;
		}
		if (fork() == 0)
		{
			executeCMD(create_cmd(line, PATHS));
		}
		wait(0);
	}
	return (0);
}

