#include "shell.h"
/**
 * get_path_dirs - get the path
 * @path_dirs : the path
 */
void get_path_dirs(char *path_dirs[])
{
	char *path_env = getenv("PATH");
	char *token = strtok(path_env, ":");
	int i = 0;

	while (token != NULL)
	{
		path_dirs[i++] = token;
		token = strtok(NULL, ":");
	}

	path_dirs[i] = NULL;
}
