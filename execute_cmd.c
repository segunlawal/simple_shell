#include "shell.h"
/**
 * execute_cmd - execute command passed from standard input
 * @argv: argument vector
 * Return: Nothing
 */

void execute_cmd(char **argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
	}
	else if (pid == 0)
	{
		/* Child process */
		char *comm = argv[0];
		char *comm_path = get_path(comm);

		if (execve(comm_path, argv, NULL) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				fprintf(stderr, "Command exited with status %d\n", exit_status);
			}
		}
		else if (WIFSIGNALED(status))
		{
			int sig = WTERMSIG(status);

			fprintf(stderr, "Command killed by signal %d\n", sig);
		}
	}
}

