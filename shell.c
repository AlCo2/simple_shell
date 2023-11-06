#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


char *check_path(char *token,char **PATHS)
{
	struct stat st;
	int i=0;
	while (PATHS[i])
	{
		char *temp = malloc(strlen(PATHS[i])+strlen(token)+2);
		strcpy(temp, PATHS[i]);
		strcat(temp, "/");
		strcat(temp, token);
		if(stat(temp, &st) == 0)
		{
			return (temp);
		}
		free(temp);
		i++;
	}
	return NULL;
}

char **create_path_list(){
	char *paths = getenv("PATH");
	char **list = NULL;
	char *token;
        token = strtok(paths, ":");
        int i = 0;
        while(token){
                i++;
                list = (char**)realloc(list,i*sizeof(char*));
                list[i-1] = malloc(strlen(token)+1);
                strcpy(list[i-1], token);
		token = strtok(NULL, ":");
        }
	return list;
}

void executeCMD(char **av){
	if (fork() == 0)
	{
		if (execve(av[0], av, NULL) == -1)
			perror("Error");
	}
}

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
		if(result){
			if(fork()==0){
				execve(result, av, NULL);
			}
		}
		else
			executeCMD(av);
		for (i = 0; i < av_count; i++)
		{
			free(av[i]);
		}
		wait(&status);
	}
	return (0);
}

