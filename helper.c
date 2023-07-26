#include "shell.h"
/**
 * parse_arguments - extracting the individual
 * command and its arguments from input line
 * @line : the line commande
 * @args : the argument
 * Return: the number of argemnt
 */

int parse_arguments(char *line, char *args[])
{
	int arg_count = 0;
	char *token = strtok(line, " \n");

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;

		if (arg_count >= MAX_ARGS)
			break;

		token = strtok(NULL, " \n");
	}

	args[arg_count] = NULL;
	return (arg_count);
}
