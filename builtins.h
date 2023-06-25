#ifndef BUILTINS_H
#define BUILTINS_H

#define MAX_ALIASES 100
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_COMMAND_LENGTH 100
typedef struct {
    char name[MAX_ALIAS_NAME_LENGTH];
    char command[MAX_ALIAS_COMMAND_LENGTH];
} Alias;

Alias aliases[MAX_ALIASES];
extern int alias_count;

void execute_cd_command(char* const arguments[]);
void execute_exit_command();
void execute_help_command();
void execute_history_command();
void execute_alias_command(char* const arguments[]);
void execute_mkdir_command(char* const arguments[]);
void execute_rmdir_command(char* const arguments[]);


#endif /* BUILTINS_H */
