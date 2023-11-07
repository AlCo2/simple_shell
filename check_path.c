#include "shell.h"

char *check_path(char *token,char **PATHS)
{
        struct stat st;
        char *temp = NULL;
        if(strchr(token, '/')!=NULL){
                temp = strdup(token);
                if(temp==NULL){
                        perror("Out of memory");
                        exit(1);
                }
                if(stat(temp, &st) == 0){
                        return temp;
                }
                free(temp);
                return NULL;
        }
        int i=0;
        while (PATHS[i])
        {
                char *temp = malloc(strlen(PATHS[i])+strlen(token)+2);
                if(temp==NULL){
                        perror("out of memory");
                        exit(1);
                }
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

