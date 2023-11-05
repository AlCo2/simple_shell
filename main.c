#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv){
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;
	pid_t pid;
	while(1){
		printf("$ ");
		nread = getline(&line, &len, stdin);
		line[nread-1] = '\0';
		char* token = strtok(line," ");
		if(fork()==0)
			execve(token, NULL, NULL);

		wait(&status);

	}
	return 0;
}

