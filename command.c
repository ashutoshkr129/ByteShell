#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "command.h"
#include "utils.h"

void execute_system_command(const char* command, char* const arguments[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(command, arguments);
        error_handler("Error executing command");
        exit(1);
    } else if (pid < 0) {
        // Error occurred while forking
        error_handler("Error forking process");
    } else {
        // Parent process
        wait(NULL);
    }
}

void execute_built_in_command(const char* command, char* const arguments[]) {
    // Implement any additional built-in commands here
}
