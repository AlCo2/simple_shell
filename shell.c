#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;
	char *token = NULL;
	char **av = NULL;
	struct stat st;

	while (1)
	{
		size_t av_count = 0;
		size_t i;

		printf("\n$ ");
		nread = getline(&line, &len, stdin);
		line[nread - 1] = '\0';
		token = strtok(line, " ");
		if (stat(token, &st) != 0)
		{
			printf("%s: 1: not found\n", token);
			continue;
		}
		while (token != NULL)
		{
			av_count++;
			av = (char **)realloc(av, av_count * sizeof(char *));
			if (av == NULL)
			{
				perror("out of memory");
				return (1);
			}
			av[av_count - 1] = malloc(strlen(token) + 1);
			if (av[av_count - 1] == NULL)
			{
				perror("out of memory");
				return (1);
			}
			strcpy(av[av_count - 1], token);
			token = strtok(NULL, " ");
		}
		free(token);
		if (fork() == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				perror("Error");
		}
		for (i = 0; i < av_count; i++)
		{
			free(av[i]);
		}
		wait(&status);
	}
	return (0);
}

