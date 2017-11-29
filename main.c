#include "headers.h"

int main() {
  char * args = malloc(20);
  while (1) {
    //scanf("%s", args);
    args = fgets(args, 20, stdin);
    strtok(args, "\n");
    //printf("argS %s\n", args);
    //char ** semi = run_cmd(args);
    runner(space_sep(args));
  }
  return 0;
}
