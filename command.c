#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "command.h"
#include "utils.h"
#include "builtins.h"

#define MAX_ARGUMENTS 100

void execute_system_command(const char* command, char* const arguments[]) {
    // Check if the entered command is an alias
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(arguments[0], aliases[i].name) == 0) {
            // Create a new argument list with the alias command and provided arguments
            char* alias_command = aliases[i].command;
            char* alias_arguments[MAX_ARGUMENTS];

            // Copy the alias command into the argument list
            alias_arguments[0] = alias_command;

            // Copy the provided arguments into the argument list
            int arg_index = 1;
            while (arguments[arg_index] != NULL && arg_index < MAX_ARGUMENTS - 1) {
                alias_arguments[arg_index] = arguments[arg_index];
                arg_index++;
            }
            alias_arguments[arg_index] = NULL;

            // Execute the alias command
            execute_system_command(alias_command, alias_arguments);
            return;
        }
    }

    if (strcmp(command, "checkpid") == 0) {
        pid_t shell_pid = getpid();

        // Construct the shell command to retrieve PIDs
        char cmd[100];
        snprintf(cmd, sizeof(cmd), "ps -e -o pid=");

        printf("Process IDs (PIDs):\n");
        system(cmd);

        printf("Shell PID: %d\n", shell_pid);
    }
    else if (strcmp(command, "kill") == 0) {
        // Check if the PID argument is provided
        if (arguments[1] != NULL) {
            // Convert the PID argument to an integer
            pid_t pid = atoi(arguments[1]);

            // Send the termination signal (SIGTERM) to the specified process
            if (kill(pid, SIGTERM) == 0) {
                printf("Process with PID %d terminated.\n", pid);
            } else {
                perror("kill");
            }
        } else {
            printf("Invalid usage of kill command. Usage: kill <pid>\n");
        }
    }
    else if (strcmp(command, "echo") == 0) {
        // Iterate through arguments to be echoed
        for (int i = 1; arguments[i] != NULL; i++) {
            printf("%s ", arguments[i]);
        }
        printf("\n");
    }
    
    else if (strcmp(command, "help") == 0) {
        execute_help_command();
    
    } else if (strcmp(command, "exit") == 0) {
        execute_exit_command();
    
    } else if (strcmp(command, "cd") == 0) {
        execute_cd_command(arguments);
    
    } else if (strcmp(command, "history") == 0) {
        execute_history_command();
    
    } else if (strcmp(command, "alias") == 0) {
        execute_alias_command(arguments);
    
    } else if (strcmp(command, "mkdir") == 0) {
        execute_mkdir_command(arguments);

    } else if (strcmp(command, "rmdir") == 0) {
        execute_rmdir_command(arguments);

    } else{
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
}


