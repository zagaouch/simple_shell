#include "shell.h"

/**
 * printEnvironment - Environment handling
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
