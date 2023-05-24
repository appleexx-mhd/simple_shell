#include "shell.h"
/**
 * lsh_read_line - function that reads input from stdin
 * Return: the line from stdin
 */
char *lsh_read_line(void)
{
#ifdef LSH_USE_STD_GETLINE
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			/*We received an EOF*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("lsh: getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
#else
#define LSH_RL_BUFSIZE 1024
	int bufsize = LSH_RL_BUFSIZE, position = 0, c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		/* If we have exceeded the buffer, reallocate.*/
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}
