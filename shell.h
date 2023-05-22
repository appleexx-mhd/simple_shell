#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
=======
#include <sys\types.h>
#include <sys/wait.h>
>>>>>>> b88bd12fefe14a6504d5f1181baf833b02ebef17

/*function to built shell*/
char *lsh_read_line(void);
int lsh_execute(char **args);
void lsh_loop(void);
char **lsh_split_line(char *line);
char *lsh_read_line(void);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

#endif