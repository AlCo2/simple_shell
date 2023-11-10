#include "shell.h"

/**
 * main - the main function that run the loop for the shell
 *
 * @argc: total argv passed
 * @argv: arguments passed to program
 *
 * Return: (0)
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char **PATHS = create_path_list();
	int i, cmd_count = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		cmd_count++;
		if (isatty(fileno(stdin)))
		{
			printf("$ ");
		}
		nread = getline(&line, &len, stdin);
		if (nread == -1)
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
		if (line[0] == 'c' && line[1] == 'd' && line[2] == ' ')
		{
			if (chdir(line + 3) == -1)
			{
				printf("%s: %d: can't cd to %s\n", argv[0], cmd_count, line + 3);
			}
			continue;
		}
		if (fork() == 0)
		{
			executeCMD(create_cmd(line, PATHS), argv[0], cmd_count);
		}
		wait(0);
	}
	return (0);
}

