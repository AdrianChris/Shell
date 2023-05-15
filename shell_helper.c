#include "main.h"

/**
 * process_input - Processes the input string and splits it into arguments
 * @shellptr: The input string to process
 * @delim: The delimiter to use for splitting
 * @argc: Pointer to store the number of arguments
 *
 * Return: An array of strings containing the arguments
 */

char **process_input(const char *shellptr, const char *delim, int *argc)
{
	char *shellptr_new = NULL;
	char **argv = NULL;
	char *token;
	int count = 0;
	int i = 0;

	shellptr_new = malloc((strlen(shellptr) * sizeof(char)) + 1);
	if (shellptr_new == NULL)
	{
		printf("Memory allocation error");
		return (NULL);
	}
	strcpy(shellptr_new, shellptr);
	token = strtok(shellptr_new, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (count + 1));
	token = strtok(shellptr_new, delim);
	for (i = 0; token != NULL; i++, token = strtok(NULL, delim))
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
	}

	argv[count] = NULL;
	*argc = count;
	return (argv);
}

