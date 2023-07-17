#include "shell.h"

/**
 * main - execute the commende line
 * Return 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	printf("$ ");
	fflush(stdout);

	while (fgets(command, sizeof(command), stdin))
	{
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
		{
			printf("$ ");
			fflush(stdout);
			continue;
		}
		shell_commande(command, NULL);
		printf("$ ");
		fflush(stdout);
	}

	return 0;
}
