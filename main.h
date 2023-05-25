
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_COMMAD 10

void shell_prompt(char **av, char **env);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);


void execute_env(char **env);
void execute_exit(void);
void execute_command(char *argv[], char *env[]);
void tokenize_input(char *prompt, char *argv[]);
ssize_t prompt_user(char **prompt, size_t *n);
void trim_newline(char *str);
void execute_shell_command(char **argv, char **env);

#endif
