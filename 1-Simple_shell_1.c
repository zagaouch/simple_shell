#include "shell.h"
/**
 * promr - to printf the promp
 */
void prompt(void)
{
	printf("#cisfun$ ");
}

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        // Child process
        if (execlp(command, command, NULL) == -1) {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char *command = NULL;
    size_t buffer_size = 0;
    ssize_t characters_read;

    while (1) {
        prompt();

        characters_read = getline(&command, &buffer_size, stdin);

        if (characters_read == -1) {
            // Handle "Ctrl+D" (EOF)
            printf("\n");
            break;
        }

        // Remove the newline character from the command
        command[characters_read - 1] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        execute_command(command);
    }

    free(command);
    return 0;
}
