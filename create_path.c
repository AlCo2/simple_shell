#include "shell.h"

char **create_path_list()
{
	char *paths = getenv("PATH");
	char **list = NULL;
	char *token;
	int i = 0;

	token = strtok(paths, ":");
	while (token)
	{
		i++;
		list = (char **)realloc(list, i * sizeof(char *));
		if (list == NULL)
		{
			perror("Out of memory");
			exit(1);
		}
		list[i - 1] = malloc(strlen(token) + 1);
		if (list[i - 1] == NULL)
		{
			perror("Out of Memory");
			exit(1);
		}
		strcpy(list[i - 1], token);
		token = strtok(NULL, ":");
	}
	free(token);
	return list;
}

