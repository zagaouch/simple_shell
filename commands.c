#include "shell.h"
/**
 * executeCommand - fucntion to execute the commande
 * @command : the command
 */

void executeCommand(const char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *command_copy = strdup(command);
		char *args[] = {command_copy, NULL};

		if (execve(command_copy, args, environ) == -1)
		{
			fprintf(stderr, "Command '%s' not found\n", command);
			free(command_copy);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
				fprintf(stderr, "Command '%s' exited status %d\n", command, exit_status);
		}
		else if (WIFSIGNALED(status))
		{
			int signal_number = WTERMSIG(status);

fprintf(stderr, "Command '%s' terminated signal %d\n", command, signal_number);
		}
	}
}
