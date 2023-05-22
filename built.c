#include "shell.h"

/*
 * Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

/*
 * List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};
/**
 * lsh_num_builtins - giving the total amount of storage required
 * Return: the storage required
 */
int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/*
 * Builtin function implementations.
*/

/**
 * lsh_cd - function for builting command
 * @args: list of args.
 * Return: Always returns 1, to continue executing.
 */
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 * lsh_help - function for  print help.
 * @args: array of args
 * Return: Always returns 1, to continue executing.
 */
int lsh_help(char **args)
{
	int i;

	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * lsh_exit - for exit the simple shell.
 * @args: list of args
 * Return: Always returns 0, to terminate execution.
 */
int lsh_exit(char **args)
{
	return (0);
}

/**
 * lsh_execute - for exucuting the shell commands
 * @args: list of args
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int lsh_execute(__attribute__((unused)) char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/* An empty command was entered.*/
		return (1);
	}

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (lsh_launch(args));
}
