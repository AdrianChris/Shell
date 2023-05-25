#include "main.h"

/**
 * main - Entry point of the program
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		shell_prompt(av, env);
	}
	return (0);
}
