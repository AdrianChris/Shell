#include "main.h"
/**
* execute_env - Prints the environment variables
* @env: Array of environment variables
*/
void execute_env(char **env)
{
int i = 0;
while (env[i])
{
printf("%s\n", env[i]);
i++;
}
}
