#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys\types.h>
/*#include <sys/wait.h>*/

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM "\t\r\n\a"

/*prototype functions*/
char **lsh_split_line(char *line);
char *lsh_getline(void);
int lsh_launch(char **args);
int lsh_execute(char **args)
/*function declarations for builtin shell commands*/
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

#endif
