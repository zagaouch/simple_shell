#include "shell.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **comds = NULL, *line = NULL, s_name = NULL, **current_cmd = NULL;
	int i, type_command = 0, status = 0;;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	s_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			comds = tokenizer(line, ";");

		for (i = 0; comds[i] != NULL; i++)
		{
			current_cmd = tokenizer(comds[i], " ");
			if (current_cmd[0] == NULL)
			{
				free(current_cmd);
				break;
			}
			type_command = parse_command(current_cmd[0]);

			/* initializer -   */
			initializer(current_cmd, type_command);
			free(current_cmd);
		}
		free(comds);
	}
	free(line);

	return (status);
}

	
