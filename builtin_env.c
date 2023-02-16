#include "main.h"
/**
 * builtin_env - prints environment variables
 * Return: Nothing
 */

void builtin_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
