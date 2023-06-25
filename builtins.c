#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "builtins.h"
#include "utils.h"
#include <unistd.h>

typedef struct {
    const char* name;
    const char* description;
} CommandInfo;

extern char* command_history[];
extern int history_count;
int alias_count = 0;


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
        system("pwd");
    }
}

void execute_alias_command(char* const arguments[]) {
    if (arguments[1] == NULL || arguments[2] == NULL) {
        printf("Usage: alias <alias_name> <command>\n");
        return;
    }

    if (alias_count >= MAX_ALIASES) {
        printf("Maximum number of aliases reached.\n");
        return;
    }

    // Store the alias in the aliases array
    strncpy(aliases[alias_count].name, arguments[1], MAX_ALIAS_NAME_LENGTH - 1);
    strncpy(aliases[alias_count].command, arguments[2], MAX_ALIAS_COMMAND_LENGTH - 1);
    alias_count++;

    printf("Alias created: %s -> %s\n", arguments[1], arguments[2]);
}

void execute_mkdir_command(char* const arguments[]) {
    // Check if the correct number of arguments is provided
    if (arguments[1] != NULL) {
        int result = mkdir(arguments[1], 0777); // Create the directory with read, write, and execute permissions for all
        if (result == 0) {
            printf("Directory created: %s\n", arguments[1]);
        } else {
            printf("Error creating directory: %s\n", arguments[1]);
        }
    } else {
        printf("Error: Missing directory name\n");
    }
}

void execute_rmdir_command(char* const arguments[]) {
    // Check if the correct number of arguments is provided
    if (arguments[1] != NULL) {
        int result = rmdir(arguments[1]); // Remove the directory
        if (result == 0) {
            printf("Directory removed: %s\n", arguments[1]);
        } else {
            printf("Error removing directory: %s\n", arguments[1]);
        }
    } else {
        printf("Error: Missing directory name\n");
    }
}

void execute_exit_command() {
    printf("Exiting the shell...\n");
    exit(EXIT_SUCCESS);
}

void execute_help_command() {
    const CommandInfo commands[] = {
        {"ls", "List files and directories in the current directory."},
        {"cd", "Change the current directory."},
        {"echo", "Print arguments to the standard output."},
        {"help", "Display a list of available commands."},
        {"exit", "Exit the shell."},
        {"kill", "Send a signal to terminate a process."}

    };

    printf("Available commands:\n");

    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        printf("- %s: %s\n", commands[i].name, commands[i].description);
    }
}

void execute_history_command() {
    printf("Command history:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i + 1, command_history[i]);
    }
}
