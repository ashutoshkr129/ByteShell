#include <stdio.h>
#include <stdlib.h>
#include "builtins.h"
#include "utils.h"
#include <unistd.h>

extern char* command_history[];
extern int history_count;

void execute_cd_command(char* const arguments[]) {
    if (arguments[1] == NULL) {
        // No directory provided, go to the home directory
        const char* home_directory = getenv("HOME");
        if (home_directory != NULL) {
            if (chdir(home_directory) != 0) {
                error_handler("Error changing directory");
            }
        } else {
            printf("Home directory not found\n");
        }
    } else {
        // Change to the specified directory
        if (chdir(arguments[1]) != 0) {
            error_handler("Error changing directory");
        }
    }
}

void execute_exit_command() {
    printf("Exiting the shell...\n");
}

void execute_help_command() {
    printf("Available commands:\n");
    printf("- ls: List files and directories\n");
    printf("- help: Display available commands\n");
    printf("- exit: Exit the shell\n");
    printf("- cd <directory>: Change the current working directory\n");
    printf("- history: Display command history\n");
}

void execute_history_command() {
    printf("Command history:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i + 1, command_history[i]);
    }
}
