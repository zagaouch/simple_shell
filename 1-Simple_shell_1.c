#include "shell.h"
/**
 * prompt - to printf the promp
 */
void prompt(void)
{
	printf("$ ");
}
/**
 * execute_command - function to exec command
 * @command : the command
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	perror("Fork failed");
	else if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	int status;

	waitpid(pid, &status, 0);
	}
}
/**
 * main - the main function
 * Return: 0
 */
int main(void)
{
	char *command = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;

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
		execute_command(command);
	}
	free(command);
	return (0);
}
