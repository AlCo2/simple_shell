#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;
	char *token;
	char **av = NULL;
	while(1)
	{
		printf("\n$ ");
		nread = getline(&line, &len, stdin);
		line[nread-1] = '\0';
		token = strtok(line, " ");
		size_t av_count = 0;
		while(token!=NULL){
			av_count++;
			av = (char**)realloc(av, av_count * sizeof(char*));
			if(av==NULL){
				perror("out of memory");
				return 1;
			}
			av[av_count-1] = malloc(strlen(token)+1);
			if(av[av_count-1]==NULL){
				perror("out of memory");
				return 1;
			}
			strcpy(av[av_count-1], token);
			token = strtok(NULL, " ");
		}
		free(token);
		if(fork() == 0)
		{
			if(execve(av[0], av, NULL) == -1){
				perror("Error");
			}
		}
		for(size_t i=0;i<av_count;i++){
			free(av[i]);
		}
		wait(&status);
	}
	return 0;
}

