#include "main.h"

void shelly_prompt(char **av, char **env) {
    char *shellptr = NULL, *shellptr_new = NULL;
    ssize_t shelly_input;
    size_t t = 0;
    int count = 0, i = 0, counter = 0, status;
    char *token;
    const char *delim = " \n";
    char **argv;
    pid_t process;

    (void)av;
    (void)env;

    while (1) {
        printf("shelly$ ");
        shelly_input = getline(&shellptr, &t, stdin);
        if (shelly_input == -1) {
            if (feof(stdin)) {
                printf("\n");
                break; /* End of file condition */
            }
            perror("Error");
            exit(EXIT_FAILURE);
        }

        /* Remove trailing newline character if present */
        if (shellptr[shelly_input - 1] == '\n') {
            shellptr[shelly_input - 1] = '\0';
        }

        shellptr_new = malloc(sizeof(char) * (shelly_input + 1));
        if (shellptr_new == NULL) {
            printf("Memory allocation error");
            break;
        }

        strcpy(shellptr_new, shellptr);

        token = strtok(shellptr_new, delim);
        while (token != NULL) {
            count++;
            token = strtok(NULL, delim);
        }

        argv = malloc(sizeof(char *) * (count + 1));
        token = strtok(shellptr_new, delim);
        for (i = 0; token != NULL; i++) {
            argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[count] = NULL;

        process = fork();
        if (process == -1) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (process == 0) {
            execute(argv);
            exit(EXIT_SUCCESS);
        } else {
            wait(&status);
        }

        /* Free allocated memory */
        for (counter = 0; counter < count; counter++) {
            free(argv[counter]);
        }
        free(argv);
        free(shellptr_new);
    }

    free(shellptr);
}

