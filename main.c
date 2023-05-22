#include "shell.h"

void sh_loop(void)
{
    char **line;
    char **args;
    int status;

    do
    {
        printf("$ ");
        line = lsh_getline();
        args = lsh_split_line;
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
    
}
int main(int argc, char **argv)
{
    sh_loop();
    /*Perform any shutdown/cleanup*/
    return EXIT_SUCCESS;    
}