#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define MAXLEN 512
#define MAXTOKENS 10

char* get_line();
int execute(char**, pid_t);
char** get_av(char*);

#endif /* MAIN */

