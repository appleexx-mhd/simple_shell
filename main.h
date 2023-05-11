#ifndef MAIN_H
#define MAIN_H

#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void execmd(char **argv);
char *get_locations(char *command);

#endif /*MAIN_H*/
