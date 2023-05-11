#include "main.h"

void execmd(char **argv)
{
    char *command = NULL;
    char *path_command = NULL;

    if (argv)
    {
        command = argv[0];

        path_command = get_locations(command);
        if (execve(path_command, argv, NULL))
        {
            perror("Error: ");
        }
        
    }
    
}