#include "shell.h"

/**
 * create_path_list - a function that take ENV PATH and create a list of it
 *
 * Return: return PATH list
*/

char **create_path_list()
{
	char *paths = getenv("PATH");
	char **list = NULL;

	list = split_string(paths, ":");
	return (list);
}

