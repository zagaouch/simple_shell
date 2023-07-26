#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 100
/* fucntion liste */
void shell_commande(char *command, char *envp[]);
void shell_command(char *command, char *arguments[]);
int main(void);
#endif
