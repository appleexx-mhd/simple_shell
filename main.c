#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(Shell) $";
    char *lineptr;
    size_t b = 0;

    // declaring void variables
    (void)ac;
    (void)argv;
    // infinte loop
    while (1) {
        printf("%s", prompt);
        getline(&lineptr, &b, stdin);
        printf("%s\n", lineptr);
        // free the allocated memory after every execution
        free(lineptr);
    }
    return 0;
}