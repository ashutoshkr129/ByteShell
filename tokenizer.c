#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "utils.h"

char** tokenize_input(const char* input) {
    int max_tokens = 10;
    char** tokens = (char**)malloc(max_tokens * sizeof(char*));

    char* token = strtok((char*)input, " \t");
    int token_count = 0;

    while (token != NULL) {
        tokens[token_count] = strdup(token);
        token_count++;

        if (token_count >= max_tokens) {
            max_tokens += 10;
            tokens = (char**)realloc(tokens, max_tokens * sizeof(char*));
        }

        token = strtok(NULL, " \t");
    }

    tokens[token_count] = NULL; // Set the last element to NULL

    return tokens;
}

void free_tokens(char** tokens) {
    if (tokens == NULL) {
        return;
    }

    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }

    free(tokens);
}
