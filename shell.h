#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void prompt(void);

void execute_command(char *command, char *args[], char *path_dirs[]);
int parse_arguments(char *line, char *args[]);
void get_path_dirs(char *path_dirs[]);

#endif
