#include "main.h"

/**
 * shelly_prompt - Prompts the user for input and processes it
 */

void shelly_prompt(void)
{
	char *shellptr = NULL;
	ssize_t shelly_input;
	char **argv;
	int argc;
	const char *delim = " \n";
	size_t t;

	while (1)
	{
		printf("shelly$ ");
		shelly_input = getline(&shellptr, &t, stdin);
		if (shelly_input == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
		if (shellptr[0] == '\n')
		{
			perror("./shell");
			continue;
		}
		perror("Error");
		exit(EXIT_FAILURE);
		}

		if (shellptr[shelly_input - 1] == '\n')
		{
			shellptr[shelly_input - 1] = '\0';
		}

		argv = process_input(shellptr, delim, &argc);
		if (argv != NULL)
		{
			child_process(argv);
		}
	}

	free_memory(argv, shellptr, NULL, argc);
}

