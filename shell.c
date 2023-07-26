#include "shell.h"
/**
 * runShell - Shell implementation function
 */
void runShell(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t line_length;

	while (1)
	{
		printf("$ ");
		line_length = getline(&command, &command_size, stdin);
		if (line_length == -1)
		{
		printf("\n");
		break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
		{
		printf("Exiting the shell.\n");
		break;
		}
		else if (strcmp(command, "env") == 0)
		{
		printEnvironment();
		}
		else
		{
		executeCommand(command);
		}
	}
	free(command);
}
