#include "shell.h"
/**
 * my_strdup - duplicates string
 * @str: string to de duplicated
 * Return: duplicate of string
 */
char *my_strdup(char *str)
{
	size_t len = _strlen(str), i;
	char *newstr = malloc(len + 1);

	while (str[len] != '\0')
	{
		len++;
	}


	if (newstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		newstr[i] = str[i];
	}
	newstr[len] = '\0';

	return (newstr);
}

