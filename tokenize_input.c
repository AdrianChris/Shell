#define MAX_COMMAND 10
#include "main.h"

/**
 * tokenize_input - Tokenizes the user input into command arguments
 * @prompt: User input string
 * @argv: Array to store the command arguments
 * Return: Number of command arguments
 */
void tokenize_input(char *prompt, char *argv[])
{
	int argc = 0;
	char *token = strtok(prompt, " ");

	while (token && argc < MAX_COMMAND)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
}

