#ifndef MAIN_H
#define MAIN_H
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/** Prototypes to be used. getline function **/
void shelly_prompt(char **av, char **env);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
char *strcpy(char *dest, const char *src);
void execute(char **argv);
pid_t fork(void);
#endif
