#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(Shell) $";
    char *command= NULL;
    size_t b = 0;
    ssize_t read_char;
    char *copy_comands = NULL;
    const char *delim = "\n";
    int nbr_tokens = 0;
    int i;
    char *tokens;


    /* declaring void variables*/

    (void)ac;

    /* infinte loop*/
    while (1) {
        printf("%s", prompt);
        read_char = getline(&command, &b, stdin);

        /*check if get function failed or reashed EOF*/
        if (read_char == -1)
        {
            printf("Exiting Shell......\n");
            return (-1);
        }

        /* allocate space for copying the  executed*/
        copy_comands = malloc(sizeof(char) * read_char);
        if (copy_comands == NULL)
        {
            perror("Error!! : memory allocation Error");
            return (-1);
        }
        /* copy  to copy_comands*/
        strcpy(copy_comands, command);
        
        /*cut thed string  into an array of words*/
        
        /*calculate the number of tokens*/
        tokens = strtok(command, delim);

        while (tokens != NULL)
        {
            nbr_tokens++;
            tokens = strtok(NULL, delim);
        }
        nbr_tokens++;

        argv = malloc(sizeof(char *) * nbr_tokens);

        tokens = strtok(copy_comands, delim);
        for ( i = 0; tokens != NULL ; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(tokens));
            strcpy(argv[i], tokens);
            tokens = strtok(NULL, tokens);
        }
        argv[i] = NULL;

        /**execute the command line */
        execmd(argv);
    } 
    /* free the allocated memory after every execution*/
        free(command);
        free(copy_comands);
    return 0;
}
