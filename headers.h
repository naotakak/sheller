#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main();
char ** run_cmd(char *);
char ** space_sep(char *);
int runner(char **);
int cd(char **);

/***
    Still need pipes, redirection.
    Implement cd and exit.
    Commands not separating on ;. - I think this is fixed
    Program exiting after one command is executed.
    Not splitting on spaces.
***/
