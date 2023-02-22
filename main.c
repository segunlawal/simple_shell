#include "shell.h"

/**
 * parse_input - parses input into an array of arguments
 * @input: pointer to user input
 * @args: character array which will be used to store
 * the resulting array of parsed arguments
 * @num_args: number of parsed arguments
 * Return: Nothing
 */
void parse_input(char *input, char ***args, int *num_args)
{
	char *line_copy = strdup(input);
	char *token;
	const char *delim = " \n";
	int i;

	*num_args = 0;
	token = strtok(input, delim);
	while (token != NULL)
	{
		(*num_args)++;
		token = strtok(NULL, delim);
	}
	(*num_args)++;

	*args = malloc(sizeof(char *) * (*num_args));

	token = strtok(line_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		(*args)[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	(*args)[*num_args - 1] = NULL;

	free(line_copy);
}

/**
 * run_shell - runs the shell
 * Return: Nothing
 * Description: prompts the user for input, parses the input
 * into arguments and executes the command
 */
void run_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_val;
	int num_args, i;
	char **args;

	while (1)
	{
		printf("$ ");
		read_val = getline(&line, &len, stdin);
		if (read_val == -1)
		{
			perror("Getline failed\n");
			return;
		}

		parse_input(line, &args, &num_args);

		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting shell...\n");
			exit(0);
		}
		if (strcmp(args[0], "env") == 0)
		{
			builtin_env();
		}
		execute_cmd(args);

		for (i = 0; i < num_args; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	free(line);
}

/**
 * main - entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int ac, char **argv)
{
	(void)ac;
	(void) **argv;
	run_shell();
	return (0);
}
