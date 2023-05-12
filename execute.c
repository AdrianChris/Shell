#include "main.h"

void execute(char **argv) {
    char *command = NULL;
    if (argv) {
        command = argv[0];
    }

    if (execvp(command, argv) == -1) {
        perror("Error");
        exit(errno);
    }
}

