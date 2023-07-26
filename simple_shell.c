#include "shell.h"
/**
 * main - the main function
 * Return: 0
 */
int main(void)
{
	char *command = NULL;
	char *args[MAX_ARGS];
	char *path_dirs[MAX_ARGS];
	size_t buffer_size = 0;
	ssize_t characters_read;
	/* int arg_count = parse_arguments(command, args); */

	get_path_dirs(path_dirs);

	while (1)
	{
		prompt();

		characters_read = getline(&command, &buffer_size, stdin);

		if (characters_read == -1)
		{
			printf("\n");
			break;
		}
		command[characters_read - 1] = '\0';

		if (strcmp(command, "exit") == 0)
			break;

		execute_command(command, args, path_dirs);
	}

	free(command);
	return (0);
}
