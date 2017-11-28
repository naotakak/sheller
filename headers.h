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
void space_sep(char *);
int runner(char **, int);

/***
    Still need pipes, redirection.
    Implement cd and exit.
    Commands not separating on ;. - I think this is fixed
    Program exiting after one command is executed.
    Not splitting on spaces.
***/
