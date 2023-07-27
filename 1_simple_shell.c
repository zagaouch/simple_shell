#include "shell.h"
/**
 * shell_commande - function Display a prompt to type a command
 * @command: the command line
 * @envp: array of environment variables passed to the program
 */
void shell_commande(char *command, char *envp[])
{
	{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *argv[2];

		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, envp);
		fprintf(stderr, "Command not found: %s\n", command);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
		/*printf("#cisfun$ ");*/
		fflush(stdout);
	}
	else
	{
		fprintf(stderr, "ERROR: Fork failed\n");
		exit(EXIT_FAILURE);
	}

	}
}
