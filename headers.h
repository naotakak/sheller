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
    COMPLETED:
    - Separating on spaces
    - Printing working directory
    - separating command arguments
    - exit and cd

    BROKEN:
    - Something is wrong in main after line 7 in the while loop. There's a seg fault which I think involves fgets for some reason.
    - Separating on ; probably still broken
    - Pipes and redirection need to be implemented
***/
