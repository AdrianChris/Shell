#ifndef MAIN_H
#define MAIN_H
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND

char** process_input(const char* shellptr, const char* delim, int* argc);

void prompt_input(char *shellptr, ssize_t *shelly_input);
/** Execute commands  **/
void child_process(char **argv);
/** Free mememory **/

void free_memory(char **argv, char *shellptr, char *shellptr_new, int count);
/** Prototypes to be used. getline function **/
void shelly_prompt();
/*void shelly_prompt(char **av, char **env);*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
char *strcpy(char *dest, const char *src);
void execute(char **argv);
pid_t fork(void);
#endif
