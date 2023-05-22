#include "shell.h"


char *lsh_getline(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        /*Read a character*/
        c = getchar();

        /*if we hit EOF, replace it whit a null character and return*/
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return(buffer);
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        /*if we have  exceeded the buffer, reallocate*/
        if (position >= bufsize)
        {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "lsh: allocattion error\n");
                exit(EXIT_FAILURE);
            }
        }   
    }
}