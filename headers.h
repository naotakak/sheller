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
char ** colonoscopy(char *);
char ** space_sep(char *);
int runner(char **);
int cd(char **);

//piping and redirection

/***
    COMPLETED:
    - Separating on spaces
    - Printing working directory
    - separating command arguments
    - exit and cd
    - running multiple commands separated by ; NOTE: commands need to be formatted like ls;echo h (without spaces between commands, should be fixed)

    BROKEN:
    - Pipes and redirection need to be implemented
***/
