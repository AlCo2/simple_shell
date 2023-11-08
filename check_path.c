#include "shell.h"

/**
 * check_path - a function that check if command exist in path list
 *
 * @token: the command
 * @PATHS: the path list
 *
 * Return: Path if exist
*/

char *check_path(char *token, char **PATHS)
{
	struct stat st;
	char *temp = NULL;
	int i = 0;

	if (strchr(token, '/') != NULL)
	{
		temp = strdup(token);
		if (temp == NULL)
		{
			perror("Out of memory");
			exit(1);
		}
		if (stat(temp, &st) == 0)
			return (temp);
		free(temp);
		return (NULL);
	}
	while (PATHS[i])
	{
		temp = malloc(strlen(PATHS[i]) + strlen(token) + 2);
		if (temp == NULL)
		{
			perror("out of memory");
			exit(1);
		}
		strcpy(temp, PATHS[i]);
		strcat(temp, "/");
		strcat(temp, token);
		if (stat(temp, &st) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

