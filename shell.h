#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/*functions:                           */
char *check_path(char *token, char **PATHS);
char **create_path_list();
void executeCMD(char **av, char *argv, int cmd_count);
char **create_cmd(char *token, char **path);
char **split_string(char *input, char *delim);

#endif
