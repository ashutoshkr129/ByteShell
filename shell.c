#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "command.h"
#include "tokenizer.h"
#include "builtins.h"
#include "utils.h"

#define HISTORY_SIZE 10
char* command_history[HISTORY_SIZE];
int history_count = 0;

int main() {
    while (1) {
        printf("ByteShell> ");

        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

        // Add command to history
        if (history_count < HISTORY_SIZE) {
            command_history[history_count] = strdup(input);
            history_count++;
        } else {
            free(command_history[0]);
            for (int i = 0; i < HISTORY_SIZE - 1; i++) {
                command_history[i] = command_history[i + 1];
            }
            command_history[HISTORY_SIZE - 1] = strdup(input);
        }

        char** tokens = tokenize_input(input);
        
        if (tokens[0] != NULL) {
            execute_system_command(tokens[0], tokens);

            // if (strcmp(tokens[0], "ls") == 0) {
            //     execute_system_command("ls", tokens);
            // } else if (strcmp(tokens[0], "checkpid") == 0) {
            //     execute_system_command("checkpid", tokens);
            // } else if (strcmp(tokens[0], "kill") == 0) {
            //     execute_system_command("kill", tokens);
            // } else if (strcmp(tokens[0], "echo") == 0) {
            //     execute_system_command("echo", tokens);
            // } else if (strcmp(tokens[0], "help") == 0) {
            //     execute_help_command();
            // } else if (strcmp(tokens[0], "exit") == 0) {
            //     execute_exit_command();
            //     break;
            // } else if (strcmp(tokens[0], "cd") == 0) {
            //     execute_cd_command(tokens);
            // } else if (strcmp(tokens[0], "history") == 0) {
            //     execute_history_command();
            // } else if (strcmp(tokens[0], "alias") == 0) {
            //     execute_alias_command(tokens);
            // } else {
            //     // printf("Command not found: %s\n", tokens[0]);
            //     execute_system_command(tokens[0], tokens);
            // }
            
        }

        free_tokens(tokens);
    }

    // Cleanup history
    for (int i = 0; i < history_count; i++) {
        free(command_history[i]);
    }

    return 0;
}
