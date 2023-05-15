#include "main.h"

/**
 * child_process - Fork a child process
 * @argv: The array of arguments
 */

void child_process(char **argv)
{
	pid_t process;

	int status;

	process = fork();
	if (process == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (process == 0)
	{
		execute(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}

