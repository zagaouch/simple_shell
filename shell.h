#ifndef HEADER_SHEL
#define HEADER_SHEL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void runShell();
void executeCommand(const char *command);
void printEnvironment();

extern char **environ;


#endif
