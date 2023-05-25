#include "main.h"


/**
 * prompt_user - Displays a shell prompt and reads user input
 * @prompt: Pointer to store the user input
 * @n: Pointer to store the size of the input buffer
 * Return: Number of characters read or -1 on failure
 */
ssize_t prompt_user(char **prompt, size_t *n)
{
	printf("shelly$ ");
	return (getline(prompt, n, stdin));
}

/**
 * trim_newline - Removes the trailing newline character from a string
 * @str: String to trim
 */
void trim_newline(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

