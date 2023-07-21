#include "shell.h"

/**
 * printEnvironment - Environment handling
 */
void printEnvironment()
{
	char **env = environ;
	while (*env != NULL) {
		printf("%s\n", *env);
		env++;
	}
}
