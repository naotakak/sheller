#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main();
void run_cmd(char *);
char ** space_sep(char *);
int runner(char **);

/***
    Still need to parse args from stdin, pipes, redirection.
    Implement cd and exit.
    Commands not separating on ;.
    Program exiting after one command is executed.
    Not splitting on spaces.
***/
