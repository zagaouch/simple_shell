#ifndef HEADER_SHEL
#define HEADER_SHEL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void runShell(void);
void executeCommand(const char *command);
void printEnvironment(void);

extern char **environ;


#endif
