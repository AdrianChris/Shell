#include "main.h"
/**
* execute_command - Executes the given command
* @argv: Array of command arguments
* @env: Array of environment variables
*/
void execute_command(char *argv[], char *env[])
{
/* Handle the PATH */
char *path = getenv("PATH");
char *dir = strtok(path, ":");
char command[100];
int exists = 0;
while (dir)
{
sprintf(command, "%s/%s", dir, argv[0]);
if (access(command, F_OK) == 0)
{
exists = 1;
break;
}
dir = strtok(NULL, ":");
}
if (exists)
{
if (execve(command, argv, env) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
printf("%s: command not found\n", argv[0]);
exit(EXIT_FAILURE);
}
}

