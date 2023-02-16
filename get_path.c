#include "main.h"
/**
 * search_in_path - searches for the command in the directories
 * listed in the PATH environment variable
 * @path: the PATH environment variable
 * @comm: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *search_in_path(char *path, char *comm)
{
	char *path_cpy, *path_tkn, *file_path;
	int comm_len, dir_len;
	struct stat buffer;

	path_cpy = strdup(path);
	comm_len = strlen(comm);
	path_tkn = strtok(path_cpy, ":");

	while (path_tkn != NULL)
	{
		dir_len = strlen(path_tkn);
		file_path = malloc(comm_len + dir_len + 2);

		strcpy(file_path, path_tkn);
		strcat(file_path, "/");
		strcat(file_path, comm);
		strcat(file_path, "\0");

		if (stat(file_path, &buffer) == 0)
		{
			free(path_cpy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_tkn = strtok(NULL, ":");
		}
	}
	free(path_cpy);

	return (NULL);
}

/**
 * get_path - gets the path of the command inputted
 * @comm: command inputted
 * Return: path of command
 */
char *get_path(char *comm)
{
	char *path, *file_path;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		file_path = search_in_path(path, comm);
		if (file_path)
		{
			return (file_path);
		}
	}

	if (stat(comm, &buffer) == 0)
	{
		return (comm);
	}

	return (NULL);
}
