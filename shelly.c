#include "main.h"
#define MAX_COMMAND 10

/**
 * shell_prompt - Displays a shell prompt,
 * reads user input, and executes commands
 * @av: Array of strings representing command-line arguments
 * @env: Array of strings representing environment variables
 */
void shell_prompt(char **av, char **env)
{
	char *prompt = NULL;
	size_t n = 0;
	ssize_t count;
	char *argv[MAX_COMMAND];
	(void)av;
	while (1)
	{
		count = prompt_user(&prompt, &n);
		if (count == -1)
		{
			free(prompt);
			exit(EXIT_FAILURE);
		}

		trim_newline(prompt);
		tokenize_input(prompt, argv);

		if (strcmp(argv[0], "exit") == 0)
		{
			execute_exit();
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			execute_env(env);
		}
		else
		{
			execute_shell_command(argv, env);
		}
	}
}

/**
 * execute_shell_command - Executes a shell command
 * @argv: Array of strings representing the command and its arguments
 * @env: Array of strings representing environment variables
 */
void execute_shell_command(char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execute_command(argv, env);
	}
	else
	{
		wait(&status);
	}
}

