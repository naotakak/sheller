#include "headers.h"

int main() {
  char * args;
  char wd[100];
  printf("%s$ ", getcwd(wd, sizeof(wd)));
  while (1) {
    //scanf("%s", args);
    printf("THING\n");
    args = fgets(args, 100, stdin);
    printf("THING2\n");
    strtok(args, "\n");
    printf("argS %s\n", args);
    /***
    char ** semi;
    semi = run_cmd(args);
    for (int i = 0; i < sizeof(semi); i ++) {
      printf("semi[%d]: %s\n", i, semi[i]);
      //runner(space_sep(semi[i]));
    }
    ***/

    runner(space_sep(args));
    //printf("%s$ ", getcwd(wd, sizeof(wd)));
  }
  return 0;
}
