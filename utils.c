#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error_handler(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    perror("Details");
}