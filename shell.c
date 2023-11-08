#include "shell.h"

/**
 * main - the main function that run the loop for the shell
 *
 * Return: (0)
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **av = NULL;
	char **PATHS = create_path_list();
	int i;

	while (1)
	{
		printf("\n$ ");
		nread = getline(&line, &len, stdin);
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
		av = create_cmd(line);
		executeCMD(av);
	}
	return (0);
}

