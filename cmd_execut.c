#include "shell.h"
/**
 * execute_command - fubction that execute the command
 * @command : the comma,d
 * @path_dirs : th path
 * @args : the argument
 */
void execute_command(char *command, char *args[], char *path_dirs[])
{
	pid_t pid = fork();
	int i;

	if (pid < 0)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		if (execv(command, args) == -1)
		{
			for (i = 0; path_dirs[i] != NULL; i++)
			{
				char command_path[MAX_COMMAND_LENGTH];

		snprintf(command_path, sizeof(command_path), "%s/%s", path_dirs[i], command);
				if (access(command_path, X_OK) == 0)
				{
					execv(command_path, args);
				}
			}
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
