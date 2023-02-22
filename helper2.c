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

/**
 * _getenv - gets the value of an environment variable
 * @name: the name of the environment variable
 *
 * Return: a pointer to the value of the environment variable, or NULL if it is not found
 */
char *_getenv(const char *name)
{
    extern char **environ;
    char *value = NULL;
    size_t name_len = strlen(name);
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        if (_strncmp(name, environ[i], name_len) == 0 && environ[i][name_len] == '=')
        {
            value = environ[i] + name_len + 1;
            break;
        }
    }

    return value;
}

/**
 * _strncmp - compares the first n characters of two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of characters to compare
 *
 * Return: an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
        i++;
    }

    if (i == n)
    {
        return 0;
    }
    else
    {
        return (s1[i] - s2[i]);
    }
}

