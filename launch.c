#include "shell.h"

/**
 * lsh_launch - function for launching the shell
 * @args: list of arguments
 * Return: Always returns 1, to continue execution.
 */
int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process*/
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/*Error forking*/
		perror("lsh");
	}
	else
	{
		/*Parent process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
