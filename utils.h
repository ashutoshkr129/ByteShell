#ifndef UTILS_H
#define UTILS_H

#define HISTORY_SIZE 10

extern char* command_history[HISTORY_SIZE];
extern int history_count;

void add_to_history(const char* command);

#endif /* UTILS_H */
