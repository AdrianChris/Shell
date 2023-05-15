#include "main.h"

/**
 * execute - Parsing execvp
 * @argv: The array of arguments
 */

void execute(char **argv)
{
	char *command = NULL;


	if (argv)
	{
		command = argv[0];
	}

	if (execvp(command, argv) == -1)
	{
		perror("./shell");

	}
}

