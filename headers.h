#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main();

//run.c
void tell_run(char *);
int runner(char **);

//parse.c
char ** colonoscopy(char *);
char ** space_sep(char *);
void piper(char *);
void redirectG(char *);
void redirectL(char *);
