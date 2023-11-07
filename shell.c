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
		size_t av_count = 0;
		size_t i;
		char* result = NULL;

		printf("\n$ ");
		nread = getline(&line, &len, stdin);
		line[nread - 1] = '\0';
		token = strtok(line, " ");
		result = check_path(token, PATHS);
		while (token != NULL)
		{
			av_count++;
			av = (char **)malloc(av_count * sizeof(char *));
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
		if (result){
			free(av[0]);
			av[0] = malloc(strlen(result)+1);
			if(av[0]==NULL){
				perror("Out of memory");
				return (1);
			}
			strcpy(av[0], result);
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

