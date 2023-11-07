#include "shell.h"

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;
	char *token = NULL;
	char **av = NULL;
	char **PATHS = create_path_list();	
	struct stat st;

	while (1)
	{
		size_t i;
		char* result = NULL;
		size_t av_count = 0;

		printf("\n$ ");
		nread = getline(&line, &len, stdin);
		line[nread - 1] = '\0';
		if (strcmp(line, "exit") == 0){
			free(line);
			i=0;
			while (PATHS[i])
			{
				free(PATHS[i]);
				i++;
			}
			free(PATHS);
			break;
		}
		token = strtok(line, " ");
		result = check_path(token, PATHS);
		av = create_cmd(token, &av_count);
		if (result){
			free(av[0]);
			av[0] = malloc(strlen(result)+1);
			if (av[0]==NULL){
				perror("Out of memory");
				return (1);
			}
			strcpy(av[0], result);
			free(result);
		}
		executeCMD(av);
		for (i = 0; i < av_count; i++)
		{
			free(av[i]);
		}
		wait(&status);
	}
	return (0);
}

