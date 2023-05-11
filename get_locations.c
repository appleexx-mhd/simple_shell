#include "main.h"

char *get_locations(char *command)
{
    char *path;
    int len_com, len_dirc;
    char *token_path, *path_file;
    struct stat buff;
    char *copy_path;

    path = getenv("PATH");

    if (path)
    {
        /*duplicate the path string*/
        copy_path = strdup(path);
        len_com = strlen(command);
        /*break down the path variable and get all the avaible dirc*/
        token_path = strtok(copy_path, ":");

        while (token_path != NULL)
        {
            len_dirc = strlen(token_path);
            /*allocatre memory for sorting the cammand*/
            path_file = malloc(len_com + len_dirc + 2);
            /*built the path for the commands*/
            strcpy(path_file, token_path);
            strcat(path_file, "/");
            strcat(path_file, command);
            strcat(path_file, "/0");

            if (stat(path_file, &buff) == 0)
            {
                free(path_file);
                return (path_file);
            
            }
            else
            {
                free(path_file);
                token_path = strtok(NULL, ":");
            }
        }
        free(copy_path);

        if (stat(command, &buff) == 0)
        {
            return (command);
        }
        return (NULL);
    }

    return (NULL);
    
}   