#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(Shell) $";
    char *line;
    size_t b = 0;
    ssize_t read_char;

    // declaring void variables
    (void)ac;
    (void)argv;
    // infinte loop
    while (1) {
        printf("%s", prompt);
        read_char = getline(&line, &b, stdin);

        //check if getline function failed or reashed EOF
        if (read_char == -1)
        {
            printf("Exiting Shell......\n");
            return (-1);
        }
        
        printf("%s\n", line);

        // free the allocated memory after every execution
        free(lineptr);
    }
    return 0;
}