#include "shell.h"

/**
 *env - prints the current_environnement
 *@token_cmd: command entered
 *
 */

void env(char **token_cmd __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - exits the shell
 * @token_cmd: command entered
 *
 * Return: void
 */

void quit(char **token_cmd)
{
	int num_token = 0, arg;

	for (; token_cmd[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(token_cmd);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(token_cmd[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(token_cmd[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(token_cmd);
			free(commands);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
