#include "main.h"

/**
 * free_memory - Free allocated memory for argv, shellptr, and shellptr_new
 * @argv: The array of arguments
 * @shellptr: A Pointer to the shell input string
 * @shellptr_new: Pointer to the new shell input string
 * @count: The number of arguments in argv
 */

void free_memory(char **argv, char *shellptr, char *shellptr_new, int count)
{

	/* Free allocated memory for argv */
	if (count > 0)
	{

		int counter = 0;

		while (argv[counter] != NULL)
		{
			free(argv[counter]);
			counter++;
		}

		free(argv);
	}

	/* Free allocated memory for shellptr_new */
	free(shellptr_new);
	/* Free allocated memory for shellptr */
	free(shellptr);
}

