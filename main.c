#include "shell.h"

/**
 * lsh_loop - function to run the command loop
 * Return: void
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf(">$ ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);
		free(line);
		free(args);
	} while (status);
}

/**
 * main - the main function
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Always 0 On Success
 */
int main(int argc, char **argv)
{
	/* Load config files, if any.*/

	/* Run command loop.*/
	lsh_loop();

	/* Perform any shutdown/cleanup.*/

	return (EXIT_SUCCESS);
}
